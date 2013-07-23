#!/usr/bin/python

import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'build'))

import ecto
import ecto_simple

print '[ Doc ]'
print ecto_simple.Test.__doc__

test = ecto_simple.Test()

test.inputs.name = 'Biscuit'
# Tendril for vector<int> is not passed by reference. How to remedy?
vector = ecto.VectorInt()
vector.extend([1, 2, 3])
test.inputs.vector = vector

print '[ C++ ]'
test.process()

print '\n[ Results ]'
print 'Count:'
print '\tC++: {}'.format(test.outputs.count)
print '\tPython: {}'.format(len(test.inputs.name) + len(test.inputs.vector))
