# IntelDenoiserBatchCreator
This is simple programm, allows to create a batch file for denoising entire image sequence. 
This batch is for DeclanRussell's IntelOIDenoiser. https://github.com/DeclanRussell/IntelOIDenoiser

It just creates commands for every image in source directory, placed in a single batch file. 
Also support albedo. Place all albedo files in directory (source images directory)\\.alb\ with the same name os original file.
After running this programm, just look up in the directory, where this programm is placed, you can find there file named "!Image_sequence_batch.bat".
It is your generated batch file. 



In source directory, must be only needed files, becouse, programm creates commands for every file in the source folder. Be careful!
