# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: 2023 Rachel Mant <git@dragonmux.network>
maths = c.find_library('m', required: false)

replaygainSrcs = [
	'gain_analysis.c',
]

replaygain = static_library(
	'replaygain',
	replaygainSrcs,
	include_directories: includes,
	dependencies: [maths],
	gnu_symbol_visibility: 'inlineshidden',
	install: true
)
