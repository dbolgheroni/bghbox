#!/bin/sh

PY_LIBS=$(python3.6 -c "import os, sys; print(' '.join('{}'.format(d)
for d in sys.path if os.path.isdir(d)))")

uctags -R --format=1 --languages=python --python-kinds=-iv $PY_LIBS
