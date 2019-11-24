cgol and dynCGOL
    
    cgol is a program that emulates Conway's game of life within a finite 20 x 40 grid.
    dynCGOL is a program that emulayes Conway's game of life within a gird assigned by the user.

Prerequisites

    run: 
    $make all
    
cgol

    usage: $./cgol nameFIle.seed <ticks>
    
example:

    $./cgol diehard.seed 50
     -------------------------------------------- 
    |                                        |
    |       X                                |
    | XX                                     |
    |  X   XXX                               |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
     --------------------------------------------0
    Start? (y or n): y
    
    *
    *
    *
    
     --------------------------------------------
    | XXX                                    |
    | X XX    X                              |
    |   X X  XXX                             |
    |   X XXXX XXX                           |
    |    X     XXX                           |
    | X        XXX                           |
    | XX    X XX                             |
    |      X XX                              |
    |       XX                               |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
    |                                        |
     --------------------------------------------50
    Continue? (y or n): n
    
dynCGOL

    usage: $./dynCGOL nameFile.seed ticks rows cols
    
example:

     $./dynCGOL diehard.seed 40 10 10 
     ---------- 
    |          |
    |       X  |
    | XX       |
    |  X   XXX |
    |          |
    |          |
    |          |
    |          |
    |          |
    |          |
     ----------0
    Start? (y or n): y
    
    *
    *
    *
    
     ----------
    |   X      |
    |  XXX     |
    | XX XX    |
    |  XXX     |
    |   X      |
    |          |
    |          |
    |          |
    |          |
    |          |
     ----------40
    Continue? (y or n): n
    
