#!/usr/bin/python
#coding=utf-8
# Filename : helloworld.py

from ConfigParser import SafeConfigParser
from StringIO import StringIO
 
f = StringIO()
scp = SafeConfigParser()
 
print '-'*20, ' following is write ini file part ', '-'*20
sections = ['s1','s2']
for s in sections:
    scp.add_section(s)
    scp.set(s,'option1','value1')
    scp.set(s,'option2','value2')
 
scp.write(f)
print f.getvalue()
 
print '-'*20, ' following is read ini file part ', '-'*20
f.seek(0)
scp2 = SafeConfigParser()
scp2.readfp(f)
sections = scp2.sections()
for s in sections:
    options = scp2.options(s)
    for option in options:
        value = scp2.get(s,option)
        print "section: %s, option: %s, value: %s" % (s,option,value)

class Human(object):
    Can_Talk = True
    Can_Walk = True
    Age = 0
    Name = ["Li", "Lei"]
    def run(self, a):
        self.run = a
        print self.run
        
    def look(self):
        print self.run
 
 
a = Human()
b = Human()
 
a.Age += 1
print a.Age
print b.Age
 
a.Name[0] = "Wang"
print a.Name
print b.Name


a.run(5)
b.run(6)
a.look()
b.look()

def say(message, times = 1):
    print message * times

def getstr():
    #while True:
        #s = raw_input('Enter something : ')
        #if s == 'quit':
        #    break
        #if len(s) < 3:
        #    continue
        #print 'Input is of sufficient length'
    print "hi i'am here"
    
def printMax(x, y):
    '''Prints the maximum of two numbers.

    The two values must be integers.'''
    x = int(x) # convert to integers, if possible
    y = int(y)

    if x > y:
        print x, 'is maximum'
    else:
        print y, 'is maximum'
        

if __name__ == '__main__':
    print 'This program is being run by itself'
else:
    print 'I am being imported from another module' 

#class Person:
#    #pass # An empty block
#    #def sayHi(self):
#    #    print 'Hello, how are you?'
#    #
#    def __init__(self, name):
#        self.name = name
#    def sayHi(self):
#        print 'Hello, my name is', self.name
#
#
#p = Person("haha")
#print p    
#p.sayHi()

class Person:
    '''Represents a person.'''
    population = 0

    def __init__(self, name):
        '''Initializes the person's data.'''
        self.name = name
        print '(Initializing %s)' % self.name

        # When this person is created, he/she
        # adds to the population
        Person.population += 1

    def __del__(self):
        '''I am dying.'''
        print '%s says bye.' % self.name

        Person.population -= 1

        if Person.population == 0:
            print 'I am the last one.'
        else:
            print 'There are still %d people left.' % Person.population

    def sayHi(self):
        '''Greeting by the person.

        Really, that's all it does.'''
        print 'Hi, my name is %s.' % self.name

    def howMany(self):
        '''Prints the current population.'''
        if Person.population == 1:
            print 'I am the only person here.'
        else:
            print 'We have %d persons here.' % Person.population

swaroop = Person('Swaroop')
swaroop.sayHi()
swaroop.howMany()

kalam = Person('Abdul Kalam')
kalam.sayHi()
kalam.howMany()

swaroop.sayHi()
swaroop.howMany() 

print "lie biao zong he ceshi"

listone = [2, 3, 4]
listtwo = [2*i for i in listone if i > 2]
print listtwo 

#-----------------------------------------

print "存储、去存储测试"

import cPickle as p
#import pickle as p

shoplistfile = 'shoplist.data'
# the name of the file where we will store the object

shoplist = ['apple', 'mango', 'carrot']

# Write to the file
f = file(shoplistfile, 'w')
p.dump(shoplist, f) # dump the object to a file
f.close()

del shoplist # remove the shoplist

# Read back from the storage
f = file(shoplistfile)
storedlist = p.load(f)
print storedlist 


print "-------------------------------------"
    
printMax(3, 5)
print printMax.__doc__ 

help(printMax)

say('Hello')
say('World', 5)

print 'Hello World'
i = 5
print i
i = i+1
print i

s = '''This is a multi-line string.
This is the second line.'''
print s

getstr()


length = 5
breadth = 2
area = length * breadth
print 'Area is', area
print 'Perimeter is', 2 * (length + breadth)

for i in range(1, 5,2):
    print i
    #break
else:
    print 'The for loop is over'
    

number = 23
running = True

#while running:
#    guess = int(raw_input('Enter an integer : '))
#
#    if guess == number:
#        print 'Congratulations, you guessed it.' 
#        running = False # this causes the while loop to stop
#    elif guess < number:
#        print 'No, it is a little higher than that' 
#    else:
#        print 'No, it is a little lower than that' 
#else:
#    print 'The while loop is over.' 
#    # Do anything else you want to do here
#
#print 'Done'

#number = 23
#guess = int(raw_input('Enter an integer : '))
#
#if guess == number:
#    print 'Congratulations, you guessed it.' # New block starts here
#    print "(but you do not win any prizes!)" # New block ends here
#elif guess < number:
#    print 'No, it is a little higher than that' # Another block
#    # You can do whatever you want in a block ...
#else:
#    print 'No, it is a little lower than that' 
#    # you must have guess > number to reach here
#
#print 'Done'



        