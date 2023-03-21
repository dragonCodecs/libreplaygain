# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: 2023 Rachel Mant <git@dragonmux.network>
project(
	'libreplaygain',
	'c',
	version: '1.0.0',
	meson_version: '>= 0.63',
)

c = meson.get_compiler('c')
if c.get_id() == 'msvc'
	add_project_arguments('-D_CRT_SECURE_NO_WARNINGS', language: 'c')
endif

subdir('include')
subdir('src')

libreplaygain_dep = declare_dependency(
	link_with: replaygain,
	include_directories: includes,
	version: meson.project_version()
)
