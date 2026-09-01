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
    ani . append( img . copy() )
    #
#
#
#
ani[0] . save( 'movie.gif' ,  save_all       = True      , \
                              append_images  = ani[1:]   , \
                              duration       = 40        , \
                              loop           = 1         )
#
# duration
# The display duration of each frame, in milliseconds.
# Pass a single integer for a constant duration,
# or a list or tuple to set the duration for each frame separately.
# *** 40 milliseconds per frame == 25 frames per second ***
#
# loop
# Number of times to repeat the animation.
# Defaults to [0 = infinite].
# *** maybe ignore ***
#
# end
#