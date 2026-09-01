#
from PIL import Image
#
#
# based on the original
# from Nikita Lugovoy class of 2026
# during the 2022-2023 school year
#
from PIL import Image
#
#
#
numframes = 321
#
prefix    = 'frame'
#
padding   = 3
#
#
#
ani = []
#
for j in range( numframes ) :
    #
    num = f'{j}'
    #
    while len(num) < padding : num = ( '0' + num )
    #
    img = Image . open( f'{prefix}{num}.pgm' )
    #
    img         . save( f'{prefix}{num}.png' )
    #
# 
#
