# SPDX-License-Identifier: LGPL-2.0-only
# SPDX-FileCopyrightText: 2023 Rachel Mant <git@dragonmux.network>
c = meson.get_compiler('c')

maths = c.find_library('m', required: false)

replaygainSrcs = [
	'gain_analysis.c',
]

replaygain = library(
	'replaygain',
	replaygainSrcs,
	include_directories: includes,
	dependencies: [maths],
	gnu_symbol_visibility: 'inlineshidden',
	install: true,
	version: meson.project_version()
)
