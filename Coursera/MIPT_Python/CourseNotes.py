#USEFUL INFO

help(print) #any object
print.__doc__

"""
    Multiline comment or doc
"""

#BASIC TYPES

#Integers has unlimited size
a = 23134327514327865381276483124832984102394321

a = 13
type(a) #<class 'int'>

b = 100_123_234
c = 100_234.567_891

d = 1.5e2
type(d) #<class 'float'>

e = int(d)
f = float(a)

import decimal
import fractions

a = 4.2 + 1 # = 5.2 #float

a = 2/4 # = 0.5 (always float)

a = 2 ** 4 #= 16
a = 9 ** 0.5 #= 3

a = 10 // 3 #= 3

a = 10 % 3 # = 1

x = 3
y = 4
z = x ^ y, x & y, x | y, x << 2, y >> 1, ~x

#swap:
a = 1
b = 2
a, b = b, a

#Primitive types are immutable
a = b = 1
a += 1
print(a) #2
print(b) #1

#Mutable:
x = y = []
x.append(1)
print(x) #[1]
print(y) #[1]

b = True
type(b) #<class 'bool'>

2 == 2 #= True

x = 2
print(1 < x < 3) #True

bool(12) #True

bool(None) #False

b = None
if b is None: # or if b == None, but not idiomatic
    print('Not initialized yet')
elif not b:
    print('b = 0')

x,y = True, False
print(x and y) #False
print(not y) #True

#Lazy logical expressions
x = 12
y = False
print(x or y) #12: result is a value of x, y was not calculated

x = 12
z = 'boom'
v = x and z
print(v) #boom : last calculated value



#STRINGS

#Strings are immutable

#Quote types
print('abc')
print("def")
print("abc 'def' qwe")
print('abc "def" qwe')
print("qwe \"abc\" asd")
print("drive c:\\\\")
print(r"drive c:\\")
multiline = "abc"\
            "def"
multiline_with_spaces = """
There are two
language types:

B. Stroustup
"""
print(multiline_with_spaces)

s = "one" + "two" #ineffective as string is immutable: new allocation

s = "hello"
print (id(s)) #address: 42321313432
s += "world"
print (id(s)) #address: 42321313485 (new allocation - immutable!)


s = "one " * 3 #'one one one '

#Slices: [start:stop:step]
s = "Python course on Coursera"
s[7:] # 'course on Coursera'
s[7:12] # 'course'
s[-8:] # 'Coursera'
s = '023456789'
s[::2] # '02468'
s = 'Moscow'
s[::-1] # 'wocsoM'
"Moscow".capitalize() # "MOSCOW"
"2017".isdigit() # True

#Operator "in"
"3.14" in "Pi = 3.1415" #True

s = 'one'
for c in s:
   print(c)
#'o'
#'n'
#'e'

num_str = str(99.01) #'99.01'
type(s) # <class 'str'>

bool("nonempty") #True
bool('') #False

#Formatting:

#Way 1
s = "%s, Mr. %s"
print(s % ("Hello", "Bob")) #"Hello, Mr. Bob"

#Way 2
s = '{} is {} years old'.format('John', 25)
s = '{name} is {age} years old'.format(name = 'John', age = 25)

#Way 3
#f-strings (Python 3.6+)
name = 'John'
age = 25
s = f'{name} is {age} years old'
num = 10
s = f'Binary {num} = {num:#b}'
num = 7/3
s = f'Result = {num:.3f}' #Result = 2.333

#Way 4 - join
# From SO:
#Python 3.6 changed strings that have known components with Literal String Interpolation.

domain = 'some_really_long_example.com'
lang = 'en'
path = 'some/really/long/path/'

s1 = f'http://{domain}/{lang}/{path}' # 0.151 µs
s2 = 'http://%s/%s/%s' % (domain, lang, path) # 0.321 µs
s3 = 'http://' + domain + '/' + lang + '/' + path # 0.356 µs
s4 = ''.join(('http://', domain, '/', lang, '/', path)) # 0.249 µs (notice that building a constant tuple is slightly faster than building a constant list).


#name = input('Enter your name: ')
#print(name) #'Alex'

#Byte strings (bytes):
example_bytes = b'hello'
type(example_bytes) #<class 'bytes'>
for b in example_bytes:
   print(b)
#104
#101
#108
#108
#111

#s = b'привет'
#Error! (Unicode values > 255)

s = 'привет'
encoded_s = s.encode(encoding = "utf-8")
print(encoded_s) #b'\xd0\xbf\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82' # 'п' = 0xd0bf
#<class 'bytes'>

decoded_s = encoded_s.decode(encoding = "utf-8")
print(decoded_s)
'привет'


#FLOW CONTROL

s = "hello, world"
if "world" in s and 2 + 2 == 4:
    print("Yes!")
else:
    print("No!")

if "world" in s:
    print("Yes!")
elif 2 + 2 == 4:
    print("wow!")
else:
    print("No!")

score = '5:0'
winner = "Argentina" if score == '5:0' else "Jamaica"

somelist = None
mylist = somelist or []

i = 0
while i < 100:
   i += 1

s = 'hello'
for c in s:
    print(c)

for i in range(3):
    print(i)
#0
#1
#2

for i in range(5,8):
    print(i)
#5
#6
#7

for i in range(1,10,2):
    print(i)
#1
#3
#5
#7
#9

for i in range(1,4,-1):
    print(i)
#4
#3
#2

for _ in range(10):
   print('Ops!')

while False:
    pass

val = 1
while True:
    val += 1
    if(val > 100):
        break

sum1 = 0
for a in range(12):
    if a % 2 != 0:
        continue
    sum1 += a


#MODULES

#Python executes all top level instructions when module is imported:
#mymodule.py:
print('hello')
#>>> import mymodule
#>>> hello
#>>> import mymodule
#>>>
#second call ignored

#mkdir mypackage
#vim mypackage/__init__.py
#~ print("importing mypackage")
#python3
#>>>import mypackage
#>>>importing mypackage
#<module 'mypackage' from ...>

#module1.py:
#if __name__ == "__main__":
#   print("direct call")

#python3 module1.py
#direct call

#import module1
#<no output - indirect call>

#vim mypackage/utils.py
#python3
#>>> import mypackage.utils
#>>> mypackage.utils.myfun(1,2)

#>>> from mypackage.utils import myfun
#>>> myfun(1,2)

#>>> from mypackage.utils import *
#>>> myfun1(1,2)
#>>> myfun2(1)

#VIRTUAL ENVIRONMENT

#python -m venv myenv
#source myenv/bin/activate
#(myenv): pip install requests
#deactivate
#:
#source myenv/bin/activate
#(myenv) pip install jupyter-notebook
#(myenv) python jupyter-notebook
#(myenv) pip install requests
#(myenv) python
#(myenv) >>> import requests
#(myenv) >>> print(requests.get("http://freegeoip.net/json").json())


#INTERNALS

a.__add__(2)
dir(a) #['__abs__', '__add__,...] #30+ methods

"""
Every variable, class, function, module is:

typedef struct _object {
    _PyObject_HEAD_EXTRA
    Py_ssize_t ob_refcnt;         // Счетчик ссылок
    struct _typeobject *ob_type;  // Указатель на тип объекта
} PyObject;
typedef struct {
    PyObject ob_base;
    Py_ssize_t ob_size;  // Кол-во элементов в переменной части
} PyVarObject;
"""

#BYTECODE

#pyc - bytecode
#mutiply.__code__.co_code()
#b'|\x00|\x01\x14\x00S\x00'
import dis

def multiply(a, b):
    return a * b

dis.dis(multiply)
#2      0 LOAD_FAST         0 (a)
#       2 LOAD_FAST         1 (b)
#       4 BINARY_MULTIPLY
#       6 RETURN_VALUE

import opcode
print(opcode.opmap)


#LISTS

#List is mutable

empty_list1 = []
empty_list2 = list()

#can have various objects but usually single
lst = [10, 'str', [1, 2]]

# 10 equal items
lst = ['equals'] * 10

len(lst) #-> constant time call

#index
chars = ['a', 'b', 'c', 'd']
chars[1] == 'b'
chars[-1] == 'd'

'b' in chars #True

#init from range
range_lst = list(range(10))

#reverse list
chars[::-1]

#when use slicing - new copy is created:
range_lst is range_lst[:] #False

#iterate through list with index
collections = ['set', 'list', 'dict']
for idx, c in enumerate(collections):
   print(idx, c)
#0 set
#1 list
#2 dict

collections.append('tuple')
collections.extend(['tuple', 'frozenset']) #new list added to the end
collections += ['tuple', 'frozenset'] #equal
collections += 'tuple' #NOT equal - adds 5 new items: 't', 'u' ...

del collections[3]

print(', '.join(collections)) #set, list, dict, tuple, tuple

sorted(collections) # return copy
collections.sort() #in-place sort

sorted(collections, reverse=True)

print(reversed(collections))
#<list_reverseiterator object at 0x132431243>
print(list(reversed(collections))) #reversed is iterator
#tuple, dict, list, set

# zip
questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print('What is your {0}?  It is {1}.'.format(q, a))


#TUPLES

empty_tuple = ()
empty_tuple = tuple()

#Immutable

immutables = (int, float, str)
#immutables[0] = (list,) #error - can't change tuple!
blink = ([], [])
blink[0].append(1) # Ok - element is mutable

int in immutables

# Can be hashed
hash(tuple()) #131324

# Add coma for one element
one_elem_tuple = (1,)
guess_what = (1)
type(guess_what) # int


#DICTIONARIES

# Mutable, unsorted!(hash)

empty_dict = {}
empty_dict = dict()

#Const time search (hash)
collections_map = {
    'mutable' : [ 'list', 'set', 'dict' ],
    'immutable' : [ 'tuple', 'frozenset' ]
    }
print(collections_map['immutable'])

print('elem' in collections_map)
print('elem' in collections_map.keys())
print('elem' in collections_map.values())
print(('elem', 'val') in collections_map.items())

# Absent key:
#print(collections_map['irresistable']) # KeyError: not found
print(collections_map.get('irresistable', 'not found')) # return default
#not found
#Add absent:
collections_map['irresistable'] = ['some']

#Operator "in"
print('mutable' in collections_map)
#True

# Remove:
del collections_map['irresistable']

# Return and remove:
print(collections_map.pop('mutable'))

# Update existing
collections_map.update({'irresistable' : 'some2'})

# Iteration
for key in collections_map: # or collections_map.keys
    print(key)
for val in collections_map.values():
    print(val)
for key, val in collections_map.items():
    print(key, val)

lst_items = collections_map.items()
print(lst_items) #now list of tuples
#[('mutable', ['set', 'list']), ('immutable', ['tuple', 'frozenset')]

from collections import OrderedDict
ordered  = OrderedDict() # same as std::map C++


#SET

# Mutable, unique, unordered(hash!)

empty_set = set()
nonempty_set = {1,2,3,3}
print(nonempty_set)
#{1,2,3}

# Adding/removing/search
nonempty_set.add(5)
nonempty_set.remove(2)
nonempty_set.pop() # remove and return some value (undefined)
print('elem' in nonempty_set)

# Mathematical operations

set1 = {1}
set2 = {1,2}

union_set = set1 | set2
intersection_set = set1 & set2
difference_set = set1 - set2
symmetric_difference_set = set1 ^ set2


#FROZENSET

# Immutable

frozen = frozenset(['Anna', 'Elsa', 'Kristoff'])
#frozen.add('Olaf') #-> error!


#FUNCTIONS

def myfun(param):
    """Function documentation"""
    c = 2 + param
    return c

print(myfun.__doc__)
print(myfun.__name__)

def fun_without_return():
    pass

a = fun_without_return() #None

#Types annotation
def add(a : int, b : int) -> int:
    return a + b

add(1,2) # 3
add('still ', 'works') # 'still works'

#Params passed by reference
def extender(src_list, ext):
    src_list.extend(ext)

a = [1,2,3]
b = [4,5]

extender(a, b)
print(a) #1,2,3,4,5

#But immutable types will not change inside functions:
def replacer(tuple1, new_tuple):
    tuple1 = new_tuple

tuple1 = (1,2)
replacer(tuple1, (3,4))

print(tuple1) #(1,2)

#Better to not change values inside functions but return new val

#Named args:

def hello(people, message):
    print(people, ', ', message)

hello(people = 'John', message = 'hi!') #John, hi!
hello(message = 'hi!', people = 'John') #John, hi!
hello('John', 'hi!') #John, hi!

#Function doesn't change global val
counter = 1
def inc(val):
    val += 1
#inc(counter) -> Error

#Default args
def helloer(name, msg='hello, '):
    return msg + name
helloer('Vasya')

#Variable num of args
def printer(*args):
    type(args) #<class 'tuple'>
    for arg in args:
        print(arg)

print(1,2,3,4)
#<class 'tuple'>
#1
#2
#3
#4

#We can unfold list into list of args
lst = ['red', 'green', 'blue']
printer(lst)
#<class 'tuple'>
#red
#green
#blue

def caller1(func, params):
    return func(*params) #pass variable number of args to another function

#Variable num args and dict
def printer2(**kv_args):
    type(kv_args) #<class 'dict'>
    for k,v in kv_args.items():
        print('{key} : {val}'.format(key = k, val = v))

printer2(a=10, b=5)
#<class 'dict'>
#a: 10
#b: 5

#unfold dict to kvargs

mydict = {'k1': 25, 'k2' : 50}
printer2(**mydict)


#FILES

text_modes = ['r', 'w', 'a', 'r+']
binary_modes = ['br', 'bw', 'ba', 'br+']
f = open('filename', text_modes[1])

num_symbols_written = f.write('Some multiline\nstring')
print(num_symbols_written) #21

f.close()
#better way (will be closed):
with open('filename', 'r+') as f:
    s = f.write('tst')
#file will be closed anyway when program exits or by GC,
#but better to close as soon as we don't need it since descriptors can end

f = open('filename', 'r')
s2 = f.read(2) #2 symbols
s1 = f.read() #entre file
f.tell() # 123
f.read() # ''
f.seek(0)
f.tell() # 0

s = f.readline()
lst = f.readlines() # ['line1\n', 'line2\n',...]

f.close()
import os
os.remove('filename')
#f.read() ->i/o error


#FUNCTIONAL PROGRAMMING

#Function is a 1st class object. It can be passed as argument, created inplace etc

def caller(func, args):
    return func(*args)
def printer(who, from_city):
    print("I'm {} from {}".format(who, from_city))
caller(printer, ['Vasya', 'Moscow'])

def get_multiplier():
    def multiplier_inner(a, b):
        return a * b
    return multiplier_inner
multiplier = get_multiplier()
print(multiplier(2,3)) #6
print(multiplier.__name__) #multiplier_inner

#Closure
def get_multiplier(by):
    def inner(a):
        return a * by
    return inner

multiplier_by_2 = get_multiplier(2)
print(multiplier_by_2(5)) #10

#Library functions which simplify functional programming

#Apply function to all elements in container
def squarify(a):
    return a ** 2
results = map(squarify, range(5))
for item in results:
    print(item) #0,1,4,9,16
#Second way
print(list(map(squarify, range(5)))) #[0, 1, 4, 9, 16]

#Filter by predicate
def is_positive(n):
    return n >= 0
print(list(filter(is_positive, range(-2,3)))) #[0,1,2]

#Lambdas or anonymous functions (when we don't need separate function)
print(list(map(lambda x: x ** 2, range(10))))

print(type(lambda x: x ** 2))
#<class 'function'>

numbers = list(range(10))
print(list(map(str, numbers)))

#functools has very useful helpers!
import functools
def mult(a,b):
    return a * b
print(functools.reduce(mult, [1,3,5,7,8]))
#mult(1,3)=3
#mult(3,5)=15
#mult(15,7)=105
#mult(105,8)=840
#840

#second way
print(functools.reduce(lambda a,b: a * b, [1,3,5,7,8]))
def greeter(person, greeting):
    print('{}, {}!'.format(greeting, person))
hier = functools.partial(greeter, greeting = 'Hi')
helloer = functools.partial(greeter, greeting = 'Hello')
hier('Vasya')
helloer('Ivan Ivanovich')

#List comprehensions: a bit faster than regular loop, as well as shorter
#Can be used instead of map and filter
squares = [x ** 2 for x in range(10)]
print(squares)
even_list = [x for x in range(20) if x % 2 == 0]
print(even_list)

#Dict and set comprehensions in same way
num_to_str = {num : str(num) for num in range(10)}
print(list(num_to_str.items()))

even_set = { x for x in range(10) if x % 2 == 0}
print(list(even_set))

#Type of comprehension is generator
print(type(x for x in range(3)))
#<class 'generator'>

#zip - join sequences
numbers = list(range(5))
squares = [x ** 2 for x in numbers]
for tpl in zip(numbers, squares):
    print(tpl)
#(0,0) (1,1) (2,4) (3,9 (4,16)

print(list(zip(
  filter(bool, range(3)),
  [x for x in range(3) if x]
)))
#(1,1) (2,2)


#DECORATORS

#Decorator is function which accepts function and returns function
#Used to modify function(s) behavior

#Simplest decorator - return same function
def decorator(func):
    return func
#Synthatic sugar:
@decorator
def decorated():
    print('hello')
#It is equal to:
decorated = decorator(decorated)

#Decorator which redefines function
def decorator2(func):
    def new_func():
        pass
    return new_func
@decorator2
def decorated2():
    print('hello')
#same as decorated2 = decorator2(decorated2)
print(decorated2.__name__)
#new_func

#Decorate generic function - write result to logfile
def logger(func):
    @functools.wraps(func) #this is required to save original function name
    def wrapped(*args, **kwargs): #handle any arguments, args should come before kwargs (positional before named)
        result = func(*args, **kwargs)
        with open('log.txt', 'w') as f:
            f.write(str(result))
        return result #preserves function behavior - keeps return value for function
    return wrapped

@logger
def summator(num_list):
    return sum(num_list)
print('Summator: {}'.format(summator([1, 2, 3, 4]))) #10
print(summator.__name__) #summator - because of functools.wraps call

#Decorator with parameter - custom filename
def logger(filename):
    def decorator(func):
        def wrapped(*args, **kwargs):
            result = func(*args, **kwargs)
            with open(filename, 'w') as f:
                f.write(str(result))
            return result
        return wrapped
    return decorator

@logger('new_log.txt')
def summator(num_list):
    return sum(num_list)
# Equal to:
# summator = logger('new_log.txt')(summator) #logger() returns function
# and we call it with argument (summator) to get decorated function
summator([1, 2, 3, 4, 5, 6])
with open('new_log.txt', 'r') as f:
    print(f.read())
# 21
os.remove('new_log.txt')
os.remove('log.txt')


#Apply two decorators:
def first_decorator(func):
    def wrapped():
        print('Inside first_decorator product')
        return func()
    return wrapped
def second_decorator(func):
    def wrapped():
        print('Inside second_decorator product')
        return func()
    return wrapped

@first_decorator
@second_decorator
def decorated3():
    print('Finally called...')
# Equal to:
# decorated3 = first_decorator(second_decorator(decorated)) #second decorator applied first
decorated3()
#Inside first_decorator product
#Inside second_decorator product
#Finally called...

#Useful example of 2 decorators:
def bold(func):
    def wrapped():
        return "<b>" + func() + "</b>"
    return wrapped

def italic(func):
    def wrapped():
        return "<i>" + func() + "</i>"
    return wrapped

@bold
@italic
def hello():
    return "hello world"
# Equal to:
# hello = bold(italic(hello))

print(hello())
#<b><i>hello world</i></b>



#GENERATORS

#It is a function that contains operator yield

#Generator allows to store function state and return to it every time
#It doesn't store all range in memory, just stores state

def even_range(start, end):
    cur = start
    while cur < end:
        yield cur
        cur += 2
print(list(even_range(2,15)))

#another way to iterate:
ranger = even_range(2,5)
print(next(ranger))
print(next(ranger))
#print(next(ranger)) #-> error, out-of-range

#Useful example
def fibonacci(number):
    a = b = 1
    for _ in range(number):
        yield a
        a, b = b, a + b
for num in fibonacci(10):
    print(num)


#CLASSES

num = 13
print(type(num)) # <class 'int'>

print(isinstance(num, int)) #True
print(isinstance(num, float)) #false

class Robot:
    pass
print(dir(Robot)) # ['__delattr__', '__dict__', '__doc__', '__init__', ...]
robot = Robot()
print(robot) # <__main__.Planet object at 0x10ea82b0>

#Operate user objects as built-in:
class MyPlanet:
    pass

solarsystem = []
for _ in range(8):
    planet = MyPlanet()
    solarsystem.append(planet)

#Object is HASHABLE!
solar_system = {}
for i in range(8):
    planet = MyPlanet()
    solar_system[planet] = i

#Constructors

class Planet:
    def __init__(self, name):
        self.name = name
earth = Planet("Earth")
print(earth.name) #Earth
print(earth) #<class 'Planet'>

class Planet2:
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return self.name #print will print this string
print(earth) #Earth
#but:
lst2 = [Planet2('Mars'), Planet2('Venus')]
print(lst2) #[<__main__.Planet2 object...

class Planet3:
    def __init__(self, name):
        self.name = name
    def __repr__(self):
        return 'Planet ' + self.name
lst3 = [Planet3('Mars'), Planet3('Venus')]
print(lst3) #['Planet Mars', ...]


#Class attributes (same as static members in C++)
class Planet4:
    count = 0
    def __init__(self, name, population = None):
        self.name = name
        self.population = population or []
        Planet4.count += 1

earth = Planet4("Earth")
mars = Planet4("Mars")
print(Planet4.count) #2
print(mars.count) #2 - also valid

#Destructor
class Human:
    def __del__(self):
        print ("Goodbye!")
human = Human()
del human # Goodbye!
#But better to do some cleanup (close file etc) explicitly in methods because there
#is not guarantee that del will be called

print(earth.__dict__) # {'name' : Earth, 'ppulation' : [] }

#Adding new member:
earth.mass = 5.97e24
print(earth.__dict__) # {'name' : Earth, 'ppulation' : [], 'mass' : 5.97e24 }
#Builtin types omit capability to add new member as an optimization
#Via __slots__, you can also prevent this on user-defined classes.
#But this is merely a space optimization (no need for a dictionary for every object), not a correctness thing.
#Theoretical base is here:
#https://stackoverflow.com/questions/12569018/why-is-adding-attributes-to-an-already-instantiated-object-allowed


#But trying to access non-existing member will fail:
#print(earth.radius) #'Planet4' object has no attribute 'radius'
#print(mars.mass) #Also fails!

#Check attr exists:
if hasattr(earth, 'weight'):
    print(earth.weight)
else:
    print('No attr weight in object earth!')
if hasattr(earth, 'mass'):
    print(earth.mass)

#Constructor:
class Planet5:
    def __new__(cls, *args, **kwargs):
        print('__new__ called')
        obj = super().__new__(cls)
        return obj
    def __init__(self, name):
        print("__init__ called")
        self.name = name

earth5 = Planet5('Earth')
#__new__ called
#__init__ called
#This call is equal to:

earth52 = Planet5.__new__(Planet5, 'Earth')
if isinstance(earth52, Planet5):
    Planet5.__init__(earth52, 'Earth')

#Convention for private members - name with _:
class Human1:
    def _say(self, text):
        print(text)
#But it is possible to access any class member:
hm = Human1()
hm._say('hi!')

#@classmethod - returns class instance
def solve_puzzle(text):
    return 'Dog'

class Animal:
    def __init__(self, kind):
        self.kind = kind

    @classmethod
    def get_from_puzzle(cls, puzzle_text):
        kind_ = solve_puzzle(puzzle_text)
        return cls(kind_)

animal = Animal.get_from_puzzle('4-legs friend')
print(animal.kind)

#Example of @classmethod from  library:
dct = dict.fromkeys("12345")

#@staticmethod
class Car:

    def __init__(self, num_whells):
        self.num_whells = num_whells

    @staticmethod
    def is_valid_num_whells(num_whells):
        return num_whells == 4

print(Car.is_valid_num_whells(3))

#@property
class Robot:
    def __init__(self, power):
        self._power = power

    power = property()

    @power.setter
    def power(self, val):
        if val < 0:
            self._power = 0
        else:
            self._power = val

    @power.getter
    def power(self):
        return self._power

    @power.deleter
    def power(self):
        print('Make robot useless')
        del self._power

#Shorter way if we need only reader
class Robot2:
    def __init__(self, power):
        self._power = power

    @property
    def power(self):
        #some optional calculations
        return self._power


#Inheritance
class Pet:
    def __init__(self, name = None):
        self.name = name or 'Pet'

class Dog(Pet):
    def __init__(self, name, breed = None):
        super().__init__(name)
        self.breed = breed
    def say(self):
        return f'{self.name}, waw!'

#Multiple inheritance:

class Baby:
    def __init__(self):
        self.__size = 'small'

class SmallDog(Dog, Baby):
    def __init__(self, name, breed = None):
        # Explicit specification
        super(SmallDog, self).__init__(name)



#Test for predecessor:
print(issubclass(Dog, object)) #True: any class inherited from object!
print(issubclass(int, object)) #True
print(issubclass(SmallDog, Dog)) #True
print(issubclass(Dog, int)) #False

#Test if object has class:
smalldog = SmallDog('Black')
print(isinstance(smalldog, Dog)) #True
print(isinstance(smalldog, SmallDog)) #True
print(isinstance(smalldog, int)) #False

#investigate class hierarchy:
print(SmallDog.__mro__) #Member Resolution Order (order in which Python searches for member)

#Details about multiple inheritance are here: https://docs.python.org/3/tutorial/classes.html#inheritance


#EXCEPTIONS

#Inherit exceptions from Exception class, not BaseException
"""
BaseException
 +-- SystemExit
 +-- KeyboardInterrupt
 +-- GeneratorExit
 +-- Exception
      +-- StopIteration
      +-- StandardError
      |    +-- BufferError
      |    +-- ArithmeticError
      |    |    +-- FloatingPointError
      |    |    +-- OverflowError
      |    |    +-- ZeroDivisionError
      |    +-- AssertionError
      |    +-- AttributeError
      |    +-- EnvironmentError
      |    |    +-- IOError
      |    |    +-- OSError
      |    |         +-- WindowsError (Windows)
      |    |         +-- VMSError (VMS)
      |    +-- EOFError
      |    +-- ImportError
      |    +-- LookupError
      |    |    +-- IndexError
      |    |    +-- KeyError
      |    +-- MemoryError
      |    +-- NameError
      |    |    +-- UnboundLocalError
      |    +-- ReferenceError
      |    +-- RuntimeError
      |    |    +-- NotImplementedError
      |    +-- SyntaxError
      |    |    +-- IndentationError
      |    |         +-- TabError
      |    +-- SystemError
      |    +-- TypeError
      |    +-- ValueError
      |         +-- UnicodeError
      |              +-- UnicodeDecodeError
      |              +-- UnicodeEncodeError
      |              +-- UnicodeTranslateError
      +-- Warning
           +-- DeprecationWarning
           +-- PendingDeprecationWarning
           +-- RuntimeWarning
           +-- SyntaxWarning
           +-- UserWarning
           +-- FutureWarning
	   +-- ImportWarning
	   +-- UnicodeWarning
	   +-- BytesWarning
"""

try:
    1/0
except: #catch all exception types
    print("Divide by zero")

#The above can be bad if we press Ctrl-C inside try block since KeyboardInterrupt will also be handled
#try:
    # n = input("Enter number")
#except:
    #print("Wrong number")

try:
    lst = [1,2]
    print(lst[4])
except LookupError: #catch Exception successors (KeyError, IndexError)
    print('LookupError')

try:
    n = 1 / 2
except:
    print("Some error")
else:
    print(n)

#Several exception types:
try:
    n = 1/ 0
except ValueError:
    print('ValueError')
except ZeroDivisionError:
    print('ZeroDivisionError')

try:
    f = open('etc/hosts')
    print(1 / 0)
except Exception:
    print('Some error')
finally:
    print("We're in 'finally' block")
    f.close()

#Access exception info
try:
    f = open('etc/hosts1')
except OSError as ex:
    print(ex.errno, ':', ex.strerror)

#Raising exception and reading args
try:
    filename = '/etc/kadabra'
    if not os.path.exists(filename):
        raise ValueError("File doesn't exist", filename, 'SomeArg')
    f = open(filename)
except ValueError as ve:
    msg, filename = ve.args[0], ve.args[1]
    print(msg, filename, ve.args)

#Get trace after exception:
import traceback

try:
    with open('/file/not/found') as f:
        content = f.read()
except OSError as err:
    trace = traceback.format_exc()
    print(trace)

#Passing exception to the next level:
try:
    1 / 0
except ZeroDivisionError as ex:
    print(ex.args)
    #raise
    #or:
    #raise Exception from ex #The above exception was the direct cause of the following exception:

#Assert

try:
    assert 1 == 0, "1 != 0"
except AssertionError as ae:
    print(ae.args[0])
#In real life we don't need to handle AsserionError
#Instead we can disable them by specifying flag -O to Python

#Exception adds valuable performance cost

import timeit
s1 = """
mydict = {'foo' : 1}
for _ in range(1000):
    try:
        print(mydict['bar'])
    except KeyError:
        pass
"""
print(timeit.timeit(stmt=s1, number=1))
# 1000 loops, best of 3: 511 us per loop

s2 = """
mydict = {'foo' : 1}
for _ in range(1000):
    if 'bar' in mydict:
        _ = mydict['bar']
"""
print(timeit.timeit(stmt=s2, number=1))
# 1000 loops, best of 3: 78.3 us per loop


#MAGIC METHODS

#__init__, ___new__, __str__ already described above

#__hash__, __eq__

class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email

    def __hash__(self):
        return hash(self.email)

    def __eq__(self, other):
        return self.email == other.email

john = User('John', 'john@mail.ru')
jack = User('Jack', 'john@mail.ru')

print(john == jack) #True

print(hash(john)) # 125274383719749823
print(hash(jack)) # 125274383719749823

#__getattr__: defines behavior when attribute not found, called only when attr not found
#__getattribute__: called always when we access to attribute. We can, e.g. log access to attribute

class Researcher:
    def __getattr__(self, name):
        return 'Nothing found'

    def __getattribute__(self, name):
        print('Looking for {}'.format(name)) #override
        return object.__getattribute__(self, name)  #call original __getattribute__

obj = Researcher()

print(obj.attr)
#Loking for attr
#Nothing found
obj.myattr = 1
print(obj.myattr)
#Loking for method
#1

#__setattr__
class Ignorant:
    def __setattr__(self, name, value):
        print('Not gonna set {}'.format(name))

obj = Ignorant()

obj.myattr = '3.14'
# Not gonna set myattr

#print(obj.myattr)
#AttributeError: 'Ignorant' object has no attribute 'myattr'

#__delattr__
#We can delete or not delete attribute in this method

class Deleter:
    def __delattr__(self, item):
        value = getattr(self, item)
        print(f'Goodbye {item}, you were {value}')
        object.__delattr__(self, item)

obj = Deleter()
obj.myattr = 10
del obj.myattr
#Goodbye myattr, you were 10

#__call__
#Called when class is called

class Logger:
    def __init__(self, filename):
        self.filename = filename

    def __call__(self, func):
        with open(self.filename, 'w') as f:
            f.write('Oh yes!')
        return func
logger = Logger('log.txt')
@logger
def useless_func():
    pass
useless_func() # will do nothing but will log 'Oh yes!' to a file

#__add__, __sub__
#Redefine +/-
import random
class NoisyInt:
    def __init__(self, val):
        self.val = val
    def __add__(self, other):
        noise = random.randint(1,10)
        return self.val + other.val + noise
a = NoisyInt(10)
b = NoisyInt(20)
for _ in range(3):
    print(a+b)
#40
#39
#35

#__getitem__, __setitem__
#Defines object behavior during access by index
#Defines object behavior during setting value by index
class PascalArray:
    def __init__(self, other_list = None):
        self.lst = other_list or []
    def __getitem__(self, key):
        return self.lst[key-1]
    def __setitem__(self, key, value):
        self.lst[key-1] = value
orig_lst = [1,3,5,7,9]
pascal_array = PascalArray(orig_lst)
pascal_array[4] = 8
print(pascal_array[3], pascal_array[4]) #5, 8



#ITERATORS

for number in range(5):
    print(number)

for letter in 'python':
    print(letter)

for item in [1,2,3]:
    print(item)

iterator = iter([1,2,3])
print(next(iterator))
print(next(iterator))
print(next(iterator))
#print(next(iterator)) raises StopIteration that means we should e.g. break for loop


#Writting own iterator: implement __iter__ and __next__
class SquareIter:
    def __init__(self, start, end):
        self.current = start
        self.end = end
    def __iter__(self):
        return self
    def __next__(self):
        if self.current >= self.end:
            raise StopIteration
        result = self.current ** 2
        self.current += 1
        return result

for num in SquareIter(1,4):
    print(num)
#1,4,9


#CONTEXT MANAGERS (with...)

#To define own context manager we need to redefine 2 magic methods __enter__ and __exit__

class open_file:
    def __init__(self, filename, mode):
        self.f = open(filename, mode)
    def __enter__(self):
        return self.f #for using "as f" if needed
    def __exit__(self, *args):
        self.f.close()
with open_file('log.txt', 'w') as f:
    f.write('Hello from context manager')

# Context managers are useful for exceptions
class suppress_exception:
    def __init__(self, exc_type):
        self.exc_type = exc_type
    def __enter__(self):
        return
        #pass also valid
    def __exit__(self, exc_type, exc_val, trackback):
        if exc_type == self.exc_type:
            print('Nothing happened')
            return True #mandatory to not re-throw exception
with suppress_exception(ZeroDivisionError):
    a = 1 / 0
    #Nothing happened

#Exception suppressing already exists in library
import contextlib
with contextlib.suppress(ValueError):
    raise ValueError

#Useful application:
import time
class timer:
    def __init__(self):
        self.start = time.time()
    def get_ellapsed(self):
        return time.time() - self.start
    def __enter__(self):
        return self
    def __exit__(self, *args):
        print('Ellapsed: {}'.format(t.get_ellapsed()))
with timer() as t:
    time.sleep(0.1)
    print('Current: {}'.format(t.get_ellapsed()))
    time.sleep(0.1)


#DESCRIPTORS
#Allow to work classes, objects, methods

#Contain up to 3 methods:
class Descriptor: #name can be any
    def __get__(self, obj, obj_type):
        print('get')
    def __set__(self, obj, obj_value):
        print('set')
    def delete(self, obj):
        print('delete')

class MyClass:
    attr = Descriptor()

instance = MyClass()
instance.attr #get
instance.attr = 5 #set
#del instance.attr #delete

#Descriptors allow to redefine classes behavior invisibly for users
#Example:
class Value:
    def __init__(self):
        self.value = None
    @staticmethod
    def _prepare_value(val):
        return val * 10
    def __get__(self, obj, obj_type):
        return self.value
    def __set__(self, obj, value):
        self.value = self._prepare_value(value)

class MyVal:
    attr = Value()

myval = MyVal()
myval.attr = 10
print(myval.attr) #100

#Example: descriptor which saves all assignments to file

class ImportantValue:
    def __init__(self, amount):
        self.amount = amount
    def __get__(self, obj, obj_type):
        """
        What will be in obj and obj_type:
        class Descriptor:
            def __get__(self, obj, obj_type):
                pass

        class Class:
            attr = Descriptor()

        new_obj = Class()
        print(new_obj.attr)

        obj -> new_obj, obj_type -> Class
        """
        return self.amount
    def __set__(self, obj, value):
        with open('log.txt', 'a') as f:
            f.write('{}\n'.format(value))
        self.amount = value

class Account:
    amount = ImportantValue(100)

bobs_account = Account()
bobs_account.amount = 150 #This change is logged to a file

#Bound methods/unbound methods (functions):
class Class:
    def __init__(self):
        self.a = 5
    def method(self):
        print(self.a)

class_instance = Class()

print(class_instance.method) #<bound method Class.method of <__main__.Class object at 0x0000000002DD9C50>>
print(Class.method) #<function Class.method at 0x0000000002DE6620>
#Same method returns different objects depending ont he way it accessed
class_instance.method() #5
Class.method(class_instance) #5

#Property, ClassMethod and StaticMethod are descriptors


#SLOTS

#Limits the possible class attributes with some predefined dict

class Class1:
    __slots__ = ['name']
    def __init__(self):
        self.name = 'Vasya'

obj1 = Class1()
#obj1.familyname = 'Petrov' #AttributeError: 'Class1' object has no attribute 'familyname'

#Slots implemented as descriptors for each attribute


#METACLASSES

#Class which creates other classes

class Class2:
    pass

obj = Class2()

print(type(obj)) # <class '__main__.Class2'>
print(type(Class2)) #'type' - it creates our class. 'type' is metaclass - it creates other classes
print(type(type)) #'type' - recursive closure

#Creation and inheritance are different:
print(issubclass(Class2, type)) #False
print(issubclass(Class2, object)) #True

#Create class on-the-fly:
NewClass = type('NewClass', (), {}) #class without parents and attrs
print(NewClass) #<class '__main__.NewClass'>
print(NewClass()) #<__main__.NewClass object at 0x0000000003931A90>

#Create our own meta-class
class Meta(type):
    def __new__(cls, name, parents, attrs):
        print('Creating {}'.format(name))

        if 'class_id' not in attrs:
            attrs['class_id'] = name.lower()

        return super().__new__(cls, name, parents, attrs)


class A(metaclass=Meta):
    pass
#Creating A


class Meta2(type):
    def __init__(cls, name, bases, attrs):
        print('Initializing — {}'.format(name))

        if not hasattr(cls, 'registry'):
            cls.registry = {}
        else:
            cls.registry[name.lower()] = cls

        super().__init__(name, bases, attrs)

class Base(metaclass=Meta2): pass
class A2(Base): pass
class B(Base): pass
#Initializing — Base
#Initializing — A2
#Initializing — B
print(Base.registry) #{'a': <class '__main__.A'>, 'b': <class '__main__.B'>}
print(Base.__subclasses__()) #[<class '__main__.A'>, <class '__main__.B'>]


#ABSTRACT METHODS

from abc import ABCMeta, abstractmethod

class Sender(metaclass=ABCMeta):
    @abstractmethod
    def send(self):
        """Do something"""

class Child(Sender): pass
#Child()
#TypeError: Can't instantiate abstract class Child with abstract methods send
class Child2(Sender):
    def send(self):
        print('Sending')
print(Child2()) #<__main__.Child2 at 0x110cfa860>

#Better to use the following form of abstract class:
class PythonWay:
    def send(self):
        raise NotImplementedError


#DEBUGGING

def f():
    #import pdb
    #pdb.set_trace()
    #type: step, next, ll, b [line], continue, p, ..., q, help, help [command]
    a = 1
f()

#Another way:
#python -m pdb <code.py>


#UNITTESTS

# test_python.py

import unittest

class TestPython(unittest.TestCase):
    def test_float_to_int_coercion(self):
        self.assertEqual(1, int(1.0))

    def test_get_empty_dict(self):
        self.assertIsNone({}.get('key'))

    def test_trueness(self):
        self.assertTrue(bool(10))

    def test_integer_division(self):
        self.assertIs(10 / 5, 2)

#To run:
#>> python3 - m unittest test_python.py


# Another example with setUp and mock

"""
import requests

class Asteroid:
    BASE_API_URL = 'https://api.nasa.gov/neo/rest/v1/neo/{}?api_key=DEMO_KEY'

    def __init__(self, spk_id):
        self.api_url = self.BASE_API_URL.format(spk_id)

    def get_data(self):
        pass
        return requests.get(self.api_url).json()

    @property
    def name(self):
        return self.get_data()['name']

    @property
    def diameter(self):
        return int(self.get_data()['estimated_diameter']['meters']['estimated_diameter_max'])

    @property
    def closest_approach(self):
        closest = {
            'date': None,
            'distance': float('inf')
        }
        for approach in self.get_data()['close_approach_data']:
            distance = float(approach['miss_distance']['lunar'])
            if distance < closest['distance']:
                closest.update({
                    'date': approach['close_approach_date'],
                    'distance': distance
                })
        return closest

apophis = Asteroid(2099942)

print(f'Name: {apophis.name}')
print(f'Diameter: {apophis.diameter}m')
Name: 99942 Apophis (2004 MN4)
Diameter: 682m

import json
import unittest
from unittest.mock import patch

from asteroid import Asteroid


class TestAsteroid(unittest.TestCase):
    def setUp(self): #Method runs before each test case. Also there is a tearDown method 
        self.asteroid = Asteroid(2099942)

    def mocked_get_data(self):
        with open('apophis_fixture.txt') as f: #file contains json downloaded before 
            return json.loads(f.read())

    @patch('asteroid.Asteroid.get_data', mocked_get_data) #Decorator replaces given method with mock  
    def test_name(self):
        self.assertEqual(self.asteroid.name, '99942 Apophis (2004 MN4)')

    @patch('asteroid.Asteroid.get_data', mocked_get_data)
    def test_diameter(self):
        self.assertEqual(self.asteroid.diameter, 682)

print(f'Date: {apophis.closest_approach["date"]}')
print(f'Distance: {apophis.closest_approach["distance"]:.2} LD')

"""


#PROCESSES
#Commands: top, ps aux | grep <your_process>, lsof (show open files, including stdin, stdout, stderr - 0,1,2), strace -p <pid> (system calls)

import os
print(os.getpid())

#Fork - creates copy of parent process, with all resources and same code
#This code works in *nix:
"""
import os
import time

pid = os.fork()

if pid == 0: # we're in child process
    while True:
        print('child', os.getpid())
        time.sleep(2)    
else: #parent process
    print('parent', os.getpid())
    os.wait() #sleep until all child processes finish

>> python ex.py
parent 2411
child 2412

ps axf | grep ex.py

|  \_python3 ex.py
|     \_python3 ex.py  
|  \_grep ex.py


# Memory for parent and child process is different: 
foo = 'bar'
pid = os.fork()
if pid == 0: #child
    foo = "baz"
    print('child:', foo)
else:
    print('parent:', foo)
    
>> python ex.py
parent: bar
child: baz        

Not only memory but also file descriptors are copied when we call fork.

f.readline() #in parent process -> line1
pid = fork()
if pid == 0: #child
    f.readline() #read line 2
else: #parent
    f.readline() #read line 2 too    
 
Fork can return error, it should be checked.
It is easier to use module multiprocessing

   
"""

"""
from multiprocessing import Process, freeze_support

def fp(name):
    print('Hello from process,', name)

if __name__ == '__main__':
    freeze_support()
    p = Process (target = fp, args = ('Bob',))
    p.start() #hides fork() or other type of process creation
    p.join() #hides os.wait()

#Another way to create process:

class MyProcess(Process):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def run(self): #override
        print('Hello from process, ', self.name)

if __name__ == '__main__':
    freeze_support()
    p = MyProcess('Mike')
    p.start()
    p.join()
"""

#Threads

from threading import Thread

def ft(name):
    print('Hello from thread,', name)

thread1 = Thread(target = ft, args = ('Bob',))
thread1.start()
thread1.join()

class MyThread(Thread):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def run(self):
        print('Hello from thread,', self.name)

thread2 = MyThread('Mike')
thread2.start()
thread2.join()

#Thread pool

from concurrent.futures import ThreadPoolExecutor, as_completed

def ftp(a):
    return a * a

# .shutdown() on exit
with ThreadPoolExecutor(max_workers = 3) as pool:
    results = [pool.submit(ftp, i) for i in range(10)]

    for future in as_completed(results):
        print(future.result())
# results will be mixed in order (4, 1, 0, 9, 25...)


#Queues - preferred way for synchronization instead of locks
from queue import Queue
from threading import Thread

def tfq(q, n):
    while True:
        item = q.get()
        if item is None: #There is no way to close process in Python (to avoid inconsistent state) so we're putting special value to queue
            break
        print("Process data in thread {}: get item {}".format(n, item))

q = Queue(5) #max number of elements
th1 = Thread(target=tfq, args=(q, 1))
th2 = Thread(target=tfq, args=(q, 2))
th1.start(); th2.start()

for i in range(50):
    q.put(i) # if size is already 5 the "put" blocks until item is popped from queue

q.put(None)
q.put(None)

th1.join(); th2.join()


#Locks

import threading

#With context manager:
class Point:
    def __init__(self):
        self.mutex = threading.RLock()
        self.x = 0; self.y = 0

    def get(self):
        with self.mutex:
            return (self.x, self.y)

    def set(self, x, y):
        with self.mutex:
            self.x, self.y = x, y

#Without context manager:

mutex1 = threading.RLock()
mutex2 = threading.RLock()

def foo():
    try:
        mutex1.acquire()
        mutex2.acquire()
        print('Acquire')
    finally:
        mutex1.release() #Can cause deadlock if called from different threads since we release in incorrect order
        mutex2.release()
        print('Release')


threads = [Thread(target=foo) for _ in range(10)]

for td in threads:
    td.start()

for td in threads:
    td.join()


#Conditional variables

class MyQueue:

    def __init__(self, size=5):
        self._queue = []
        self._size = size
        self._mutex = threading.RLock()
        self._empty = threading.Condition(self._mutex) #There is default lock object for CV, but for dependent CVs we have to use common lock object
        self._full  = threading.Condition(self._mutex)

    def put(self, item):
        with self._full:
            print('trying to push element')
            while len(self._queue) >= self._size:
                print('queue is full, waiting')
                self._full.wait() #wait until queue is ready to accept new item
            print('element pushed')
            self._queue.append(item)
            self._empty.notify() #notify all other waiting threads that there is item in queue

    def get(self):
        with self._empty:
            print('trying to get element')
            while len(self._queue) == 0:
                print('queue is empty, waiting')
                self._empty.wait() #wait for element
            print('element popped')
            ret = self._queue.pop(0)
            self._full.notify() #notify all threads which wait trying to put element into a full queue
            return ret

myqueue = MyQueue()

def qput():
    for _ in range(100):
        myqueue.put(1)

def qget():
    for _ in range(100):
        myqueue.get()

threads_put = [Thread(target=qput) for _ in range(10)]
threads_get = [Thread(target=qget) for _ in range(10)]

for tp, tg in zip(threads_put, threads_get):
    tp.start()
    tg.start()

for tp, tg in zip(threads_put, threads_get):
    tp.join()
    tg.join()


#GIL (Global Interpreter Lock)

#Python's GIL is intended to serialize access to interpreter internals from different threads
#On multi-core systems, it means that multiple threads can't effectively make use of multiple cores.
#Note that Python's GIL is only really an issue for CPython, the reference implementation. Jython and IronPython don't have a GIL.
#C extension writers need to release the GIL when their extensions do blocking I/O, so that other threads in the Python process get a chance to run.

#It is better to execute CPU-bound tasks sequentially
#It is better to execute I/O-bound tasks or system calls simultaneously in threads

#GIL implemented as threading.Lock (non-recursive)
#Every thread slips for 5 ms waiting for releasing GIL

#CPU-bound example:

import time

def cpu_bound(count = 10_000_000):
    while count > 0:
        count -= 1

t0 = time.time()
cpu_bound()
cpu_bound()
print('Sequential time: ', time.time() - t0)

t0 = time.time()
tcpu1 = Thread(target = cpu_bound())
tcpu2 = Thread(target = cpu_bound())
tcpu1.start(); tcpu2.start()
tcpu1.join(); tcpu2.join()
print('Parallel time: ', time.time() - t0)

#Sequential time:  1.4420826435089111
#Parallel time:  1.9200959205627441

# как выполняется поток?

"""

a      r      a            r              a          r    a
  run  |------|    run     |--------------|   run    |----| run
------>|  IO  |----------->|      IO      |--------->| IO |----->
       |------|            |--------------|          |----|
a      r      a            r              a          r    a

a - acquire GIL
r - release GIL

"""


#SOCKETS
#Sockets are cross-platform mechanism for data exchange between processes which can run on different hosts and can be written on different languages
#It is implemented via system calls

#Server

import socket

def RunServer():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(('127.0.0.1', 10001)) #Max port is 65535. Address 127.0.0.1 means server listens only local connections. Empty or 0.0.0.0 means any interface
    sock.listen(socket.SOMAXCONN) #Parameter means size of queue for incoming connections. If overflow - "connection refused" is returned to client
    conn, addr = sock.accept() #Blocks until client connects. conn is duplex channel which supports read (recv) and write (send)

    while True:
        data = conn.recv(buffersize=1024) #1024 is a buffersize
        if not data: # client closed connection
            break
        #process data
        print(data.decode('utf-8'))

    conn.close()
    sock.close()

#Client

import socket


def RunClient():
    sock = socket.socket() #socket.AF_INET, socket.SOCK_STREAM are defaults
    sock.bind(('127.0.0.1', 10001))

    #Sorter form of 2 locks above:
    sock = socket.create_connection(('127.0.0.1', 10001))

    sock.sendall('ping'.encode('utf-8'))
    #or: sock.sendall(b'ping')
    sock.close()

#Using context managers to not forget to close connection and socket

def RunServerWithCM():
    with socket.socket() as sock:
        sock.bind(('', 10001))
        sock.listen()

        while True:
            conn, addr = sock.accept()
            with conn:
                while True:
                    data = sock.recv(1024)
                    if not data:
                        break
                    print(data.decode('utf-8'))

def RunClientWithCM():
    with socket.create_connection(('127.0.0.1', 10001)) as sock:
        sock.sendall(b'ping')
