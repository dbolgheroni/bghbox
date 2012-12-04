The symbols library/directory is specified with the following statment
into .gEDA/gafrc and/or .gEDA/gschemrc:

    (component-library "dir")

The footprint library/directory is specified in a myprj.prj file which
is used by 'gsch2pcb'. A sample is show below:

    elements-dir ./pcb-fp
    schematics myprj.sch
    output-name myprj
