project('emu8085', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c17'])

inc = include_directories('include')
subdir('src')
emu8085 = executable(
  'emu8085',
  'main.c',
  include_directories : inc,
  link_with : libemu,
  install : true
)

test('test', emu8085)