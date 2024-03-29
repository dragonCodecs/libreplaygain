/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2001 David Robinson <david@robinson.org>
 * SPDX-FileCopyrightText: Copyright (C) 2001 Glen Sawyer <mp3gain@hotmail.com>
 * SPDX-FileContributor: Modified in 2023 by Rachel Mant <git@dragonmux.network>
 */

/*
 *  ReplayGainAnalysis - analyzes input samples and give the recommended dB change
 *
 *  concept and filter values by David Robinson
 *    -- blame him if you think the idea is flawed
 *  coding by Glen Sawyer 735 W 255 N, Orem, UT 84057-4505 USA
 *    -- blame him if you think this runs too slowly, or the coding is otherwise flawed
 *
 *  For an explanation of the concepts and the basic algorithms involved, go to:
 *    http://www.replaygain.org/
 */

/**
 * Pseudo-code to process an album:
 *
 *    Float_t       l_samples [4096];
 *    Float_t       r_samples [4096];
 *    size_t        num_samples;
 *    unsigned int  num_songs;
 *    unsigned int  i;
 *
 *    gain_init_analysis ( 44100 );
 *    for ( i = 1; i <= num_songs; i++ ) {
 *        while ( ( num_samples = getSongSamples ( song[i], left_samples, right_samples ) ) > 0 )
 *            gain_analyze_samples ( left_samples, right_samples, num_samples, 2 );
 *        fprintf ("Recommended dB change for song %2d: %+6.2f dB\n", i, gain_get_title() );
 *    }
 *    fprintf ("Recommended dB change for whole album: %+6.2f dB\n", gain_get_album() );
 */

#ifndef GAIN_ANALYSIS_H
#define GAIN_ANALYSIS_H

#include <stddef.h>

#define GAIN_NOT_ENOUGH_SAMPLES  -24601
#define GAIN_ANALYSIS_ERROR           0
#define GAIN_ANALYSIS_OK              1

#define INIT_GAIN_ANALYSIS_ERROR      0
#define INIT_GAIN_ANALYSIS_OK         1

#ifdef __cplusplus
extern "C" {
#endif

typedef double  Float_t;         // Type used for filtering

/// Here's the deal : Call
int gain_init_analysis ( long samplefreq );
/// to initialize everything. Call
int gain_analyze_samples ( const Float_t* left_samples, const Float_t* right_samples, size_t num_samples, int num_channels );
/// as many times as you want, with as many or as few samples as you want.
/// If mono, pass the sample buffer in through left_samples, leave
/// right_samples NULL, and make sure num_channels = 1.

Float_t gain_get_chapter ( void );
/// will return the recommended dB level change for all samples analyzed
/// SINCE THE LAST TIME you called gain_get_chapter() OR gain_init_analysis() OR gain_get_title.

Float_t gain_get_title ( void );
/// will return the recommended dB level change for all samples analyzed
/// SINCE THE LAST TIME you called gain_get_title() OR gain_init_analysis().

Float_t gain_get_album ( void );
/// will return the recommended dB level change for all samples analyzed
/// since gain_init_analysis() was called and finalized with gain_get_title().

#ifdef __cplusplus
}
#endif

#endif /* GAIN_ANALYSIS_H */
