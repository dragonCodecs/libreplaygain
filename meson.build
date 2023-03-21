# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2023 Rachel Mant <git@dragonmux.network>
project(
	'libreplaygain',
	'c',
	version: '1.0.0',
	meson_version: '>= 0.63',
)

if cxx.get_id() == 'msvc'
	add_project_arguments('-D_CRT_SECURE_NO_WARNINGS', language: 'c')
endif

subdir('include')
subdir('src')

libreplaygain_dep = declare_dependency(
	link_with: replaygain,
	include_directories: includes,
	version: meson.project_version()
)
