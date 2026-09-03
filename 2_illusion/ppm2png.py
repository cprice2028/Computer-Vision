#
from PIL import Image
#
fname = 'example1'
#
from sys import argv
#
if len( argv ) > 1 : fname = argv[1]
#
img = Image . open( f'{fname}.ppm' )
#
img         . save( f'{fname}.png' )
#
# end
#
