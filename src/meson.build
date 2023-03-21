# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2023 Rachel Mant <git@dragonmux.network>
c = meson.get_compiler('c')

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
