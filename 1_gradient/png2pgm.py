#
from PIL import Image
#
fname = 'gradient'
#
from sys import argv
#
if len( argv ) > 1 : fname = argv[1]
#
img = Image . open( f'{fname}.png' )
#
img         . save( f'{fname}.pgm' )
#
# end
#
