# percolator

Consider the following grid:

    [x][ ][ ][x]
    [ ][x][ ][ ]
    [x][ ][ ][x]
    [x][x][ ][ ]

Percolation is defined as the ability of an object to seep through from top of the grid to the bottom given the obstacles along the way.  This application assumes the grid to be a square of a user specified size `n`, and also accepts the position of the obstacles as subsequent arguments.  Note that the position of the obstacle is specified as if the slots are laid out linearly.  For the above scenario, the input would be:
    size = 4
    args = 0 3 5 8 11 12 13
    
Usage example:

    > ./percolator <size> [<pos1> <pos2> ...]

In the above scenario, you would run:

    > ./percolator 4 0 3 5 8 11 12 13
    Percolates

However, say you insert a new obstacle at 14

    > ./percolator 4 0 3 5 8 11 12 13 14
    Does not percolate
