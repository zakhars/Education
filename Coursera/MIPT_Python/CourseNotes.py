# * Documentation

help(print)  # available for any object
print(print.__doc__)

# * Comments

# single line comment
""" Multiline comment or doc
"""

# * Basic types

a1 = 23
a2 = 23134327514327865381276483124832984102394321  # integer has unlimited size
print(type(a2))  # <class 'int'>
b1 = 100_123_234
d1 = 1.5e2
type(d1)  # <class 'float'>
c1 = 100_234.567_891
e1 = int(d1)  # explicit cast
f1 = float(a2)
a3 = 4.2 + 1  # =5.2 #float
a4 = 2 / 4  # =0.5 (always float)
a5 = 10 // 3  # =3 (int)
a6 = 2 ** 4  # 2^4=16
a7 = 9 ** 0.5  # =3
a8 = 10 % 3  # =1
z1 = a1 ^ b1
z2 = a1 & b1
z3 = a1 | b1
z4 = a1 << 2
z5 = b1 >> 1
z6 = ~a1
a1, b1 = b1, a1  # swap

# Various useful operations are here:
# import decimal
# import fractions

# Primitive types are immutable
a9 = b9 = 1
a9 += 1
print(a9)  # 2
print(b9)  # 1

# Example of mutable objects
x1 = y1 = []
x1.append(1)
print(x1)  # [1]
print(y1)  # [1]

# Boolean
b5 = True
type(b5)  # <class 'bool'>
b6 = 2 == 2  # =True
x2 = 2
print(1 < x2 < 3)  # True
bool(12)  # True

bool(None)  # False
b10 = None
if b10 is None:  # or if b == None, but not idiomatic
    print('Not initialized yet')
elif not b10:
    print('b = 0')

x3, y3 = True, False
print(x3 and y3)  # False
print(not y3)  # True

# Lazy logical expressions
x4 = 12
y4 = False
print(x4 or y4)  # 12: result is a value of x, y was not calculated
z1 = 'boom'
v1 = x4 and z1
print(v1)  # boom : last calculated value

# * Strings

# Strings are immutable

# Quote types
print('abc')
print("def")
print("abc 'def' qwe")
print('abc "def" qwe')
print("qwe \"abc\" asd")
print("drive c:\\\\")
print(r"drive c:\\")
multiline = "abc" \
            "def"

multiline_with_spaces = """
There are two
language types:

B. Stroustrup
"""
print(multiline_with_spaces)

s1 = "one" + "two"  # ineffective as string is immutable: new allocation; use "join" or other formatting ways (below)

s2 = "hello"
print(id(s2))  # address: 42321313432
s2 += "world"
print(id(s2))  # address: 42321313485 (new allocation - immutable!)

s3 = "one " * 3  # 'one one one '

# Slices: [start:stop:step]
phrase = "Python course on Coursera"
print(phrase[7:])  # 'course on Coursera'
print(phrase[7:13])  # 'course'
print(phrase[-8:])  # 'Coursera'
number = '023456789'
print(number[::2])  # '02468'
city = 'Moscow'
print(city[::-1])  # 'wocsoM'
"Moscow".capitalize()  # "MOSCOW"
"2017".isdigit()  # True

# Operator "in"
b8 = "3.14" in "Pi = 3.1415"  # True

s4 = 'one'
for c2 in s1:
    print(c2)
# 'o'
# 'n'
# 'e'

num_str = str(99.01)  # '99.01'
type(num_str)  # <class 'str'>

bool("nonempty")  # True
bool('')  # False

# Strings formatting:

# Way 1
s5 = "%s, Mr. %s"
print(s2 % ("Hello", "Bob"))  # "Hello, Mr. Bob"

# Way 2
s6 = '{} is {} years old'.format('John', 25)
s7 = '{name} is {age} years old'.format(name='John', age=25)

# Way 3
# f-strings (Python 3.6+)
first_name = 'John'
age = 25
s8 = f'{first_name} is {age} years old'
num1 = 10
s9 = f'Binary {num1} = {num1:#b}'
num1 = 7 / 3
s10 = f'Result = {num1:.3f}'  # Result = 2.333

# Way 4 - join
# From SO: Python 3.6 changed strings that have known components with Literal String Interpolation.
domain = 'some_really_long_example.com'
lang = 'en'
path = 'some/really/long/path/'

s11 = f'http://{domain}/{lang}/{path}'  # 0.151 µs
s12 = 'http://%s/%s/%s' % (domain, lang, path)  # 0.321 µs
s13 = 'http://' + domain + '/' + lang + '/' + path  # 0.356 µs
s14 = ''.join(('http://', domain, '/', lang, '/',
              path))  # 0.249 µs (building a constant tuple is slightly faster than building a constant list).

# F-strings allow to call ANY instructions inside:
sf = f'Result ={s1 + s2}'

# Filling strings with zeroes:
width = 4
print('%03d' % width)
print(format(width, '03'))
print('{foo:03d}'.format(foo=width))
print('{:03d}'.format(width))
print('{0:03d}'.format(width))
print(f'{width:03}')

# Byte strings (bytes):
example_bytes = b'hello'
type(example_bytes)  # <class 'bytes'>
for bt in example_bytes:
    print(bt)
# 104
# 101
# 108
# 108
# 111

# s = b'привет'
# Error! (Unicode values > 255)

s15 = 'привет'
encoded_s = s15.encode(encoding="utf-8")
print(encoded_s)  # b'\xd0\xbf\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82' # 'п' = 0xd0bf
# <class 'bytes'>

decoded_s = encoded_s.decode(encoding="utf-8")
print(decoded_s)  # 'привет'

# Input
# name = input('Enter your name: ')
# print(name) #'Alex'


# * Flow control

hw = "hello, world"
if "world" in hw and 2 + 2 == 4:
    print("Yes!")
else:
    print("No!")

if "world" in hw:
    print("Yes!")
elif 2 + 2 == 4:
    print("wow!")
# else: # unreachable
#     print("No!")

score = '5:0'
winner = "Argentina" if score == '5:0' else "Jamaica"

somelist = None
mylist = somelist or []

i1 = 0
while i1 < 100:
    i1 += 1

s15 = 'hello'
for cr in s15:
    print(cr)

for i2 in range(3):
    print(i2)
# 0
# 1
# 2

for i3 in range(5, 8):
    print(i3)
# 5
# 6
# 7

for i4 in range(1, 10, 2):
    print(i4)
# 1
# 3
# 5
# 7
# 9

for i5 in range(4, 1, -1):
    print(i5)
# 4
# 3
# 2

for _ in range(10):
    print('Ops!')

# Unreachable
# while False:
#    pass

val1 = 1
while True:
    val1 += 1
    if val1 > 100:
        break

sum1 = 0
for nm in range(12):
    if nm % 2 != 0:
        continue
    sum1 += nm

# * Modules

import time

time.sleep(1)

from time import sleep

sleep(1)

from time import *

sleep(1)

# Python executes all top level instructions when module is imported:
# mymodule.py:
print('hello')
# >>> import mymodule
# >>> hello
# >>> import mymodule
# >>>
# second call ignored

# mkdir mypackage
# vim mypackage/__init__.py
# ~ print("importing mypackage")
# python3
# >>>import mypackage
# >>>importing mypackage
# <module 'mypackage' from ...>

# module1.py:
# if __name__ == "__main__":
#   print("direct call")

# python3 module1.py
# direct call

# import module1
# <no output - indirect call>

# vim mypackage/utils.py
# python3
# >>> import mypackage.utils
# >>> mypackage.utils.myfun(1,2)

# >>> from mypackage.utils import myfun
# >>> myfun(1,2)

# >>> from mypackage.utils import *
# >>> myfun1(1,2)
# >>> myfun2(1)


# * Virtual environment

# python -m venv myenv
# source myenv/bin/activate
# (myenv): pip install requests
# deactivate
#:
# source myenv/bin/activate
# (myenv) pip install jupyter-notebook
# (myenv) python jupyter-notebook
# (myenv) pip install requests
# (myenv) python
# (myenv) >>> import requests
# (myenv) >>> print(requests.get("http://freegeoip.net/json").json())

# * Python internals

am = 1
am.__add__(2)
dir(am)  # ['__abs__', '__add__,...] #30+ methods

"""
Every variable, class, function, module is:

typedef struct _object {
    _PyObject_HEAD_EXTRA
    Py_ssize_t ob_refcnt;         // Ref counter
    struct _typeobject *ob_type;  // Pointer to the object type
} PyObject;

typedef struct {
    PyObject ob_base;
    Py_ssize_t ob_size;  // Number of elements in object's variable part
} PyVarObject;
"""

# * Bytecode

# pyc - bytecode
# mutiply.__code__.co_code()
# b'|\x00|\x01\x14\x00S\x00'
import dis


def multiply(p, r):
    return p * r


dis.dis(multiply)
# 2     0 LOAD_FAST         0 (a)
#       2 LOAD_FAST         1 (b)
#       4 BINARY_MULTIPLY
#       6 RETURN_VALUE

import opcode

print(opcode.opmap)

# * Lists

# List is mutable

empty_list1 = []
empty_list2 = list()

# can have various objects but usually one type
lst1 = [10, 'str', [1, 2]]

# 10 equal items
lst2 = ['equals'] * 10

len(lst2)  # -> constant time call

# index
chars = ['a', 'b', 'c', 'd']
print(chars[1] == 'b')
print(chars[-1] == 'd')

print('b' in chars)  # True

# init from range (iterator)
range_lst = list(range(10))

# when use slicing - new copy is created:
print(range_lst is range_lst[:])  # False

# reverse list
rev = chars[::-1]
print(chars)
print(rev)
chars.reverse()  # in-place reverse
print(chars)

# iterate through list with index
collections = ['set', 'list', 'dict']
for idx, col in enumerate(collections):
    print(idx, col)
# 0 set
# 1 list
# 2 dict

collections.append('tuple')
collections.extend(['tuple', 'frozenset'])  # new list contents added to the end
collections += ['tuple', 'frozenset']  # equal to 'extend'
collections += 'tuple'  # NOT equal!!! - adds 5 new items: 't', 'u' ...

del collections[3]

print(', '.join(collections))  # set, list, dict, tuple, tuple

sorted(collections)  # return copy
collections.sort()  # in-place sort
sorted(collections, reverse=True)
print(reversed(collections))  # <list_reverseiterator object at 0x132431243> - reversed is iterator
print(list(reversed(collections)))  # tuple, dict, list, set

# zip
questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for qst, answ in zip(questions, answers):  # any number of containers, !num of elements equal to shorter container size!
    print('What is your {0}?  It is {1}.'.format(qst, answ))

# * Tuples

# Tuple is immutable

empty_tuple1 = ()
empty_tuple2 = tuple()

immutables = (int, float, str)
# immutables[0] = (list,) #error - can't change tuple!
blink = ([], [])
blink[0].append(1)  # Ok - element is mutable

print(int in immutables)  # True

# Tuple can be hashed
hash(tuple())  # 131324

# Add coma when init from one element, otherwise it will not be a tuple
one_elem_tuple = (1,)
# guess_what = (1)
# type(guess_what)  # int

# * Dictionaries

# Dictionaries are mutable and unsorted! (hash)

empty_dict1 = {}
empty_dict2 = dict()

# Const time search (hash)
collections_map = {
    'mutable': ['list', 'set', 'dict'],
    'immutable': ['tuple', 'frozenset']
}
print(collections_map['immutable'])

print('elem' in collections_map)  # searches in .keys
print('elem' in collections_map.keys())  # same but explicit
print('elem' in collections_map.values())
print(('elem', 'val') in collections_map.items())
for mkey, mval in collections_map.items():
    print(mkey, mval)
lst_items = collections_map.items()
print(lst_items)  # now list of tuples
# [('mutable', ['set', 'list']), ('immutable', ['tuple', 'frozenset')]

# Absent key:
# print(collections_map['irresistible']) # KeyError: not found
print(collections_map.get('irresistible', 'not found'))  # return default - 'not found'
# Add absent:
collections_map['irresistible'] = ['some']
print(collections_map.get('irresistible', 'not found'))  # return ['some']

# Operator "in"
print('mutable' in collections_map)  # True

# Remove:
del collections_map['irresistible']

# Return and remove:
print(collections_map.pop('mutable'))

# Update existing
collections_map.update({'irresistible': 'some2'})

# Ordered dictionary is a special type:
from collections import OrderedDict

ordered = OrderedDict()  # same as std::map in C++

# * Set

# Set is mutable, unique, unordered (hash)

empty_set = set()
nonempty_set = {1, 2, 3, 3}
print(nonempty_set)  # {1,2,3}

# Adding/removing/searching
nonempty_set.add(5)
nonempty_set.remove(2)
nonempty_set.pop()  # remove and return some value (undefined)
print('elem' in nonempty_set)

# Mathematical operations

set1 = {1}
set2 = {1, 2}

union_set = set1 | set2
intersection_set = set1 & set2
difference_set = set1 - set2
symmetric_difference_set = set1 ^ set2

# * Frozenset

# Frozenset is immutable

frozen = frozenset(['Anna', 'Elsa', 'Kristoff'])


# frozen.add('Olaf') #-> error!


# * Functions

def myfun(param):
    """Function documentation"""
    res = 2 + param
    return res


print(myfun.__doc__)
print(myfun.__name__)


def fun_without_return():
    pass


# a = fun_without_return()  # None


# Types annotation
def add(u: int, w: int) -> int:
    return u + w


add(1, 2)  # 3
# add('still ', 'works')  # 'still works'


# Params passed by reference
def extender(src_list, ext):
    src_list.extend(ext)


lst1 = [1, 2, 3]
lst2 = [4, 5]

extender(lst1, lst2)
print(lst1)  # 1,2,3,4,5


# But immutable types will not change inside functions:
def replacer(old_tuple, new_tuple):
    old_tuple = new_tuple


tuple1 = (1, 2)
replacer(tuple1, (3, 4))

print(tuple1)  # (1,2)


# Better to not change values inside functions but return new val

# Named args:

def hello(people, message):
    print(people, ', ', message)


hello(people='John', message='hi!')  # John, hi!
hello(message='hi!', people='John')  # John, hi!
hello('John', 'hi!')  # John, hi!

# Function doesn't change global val
counter = 1


def inc(value):
    value += 1


# inc(counter) -> Error

# Default args
def helloer(dude, hello_msg='hello, '):
    return hello_msg + dude


helloer('Vasya')


# Variable num of args
def printer(*args):
    type(args)  # <class 'tuple'>
    for arg in args:
        print(arg)


print(1, 2, 3, 4)
# <class 'tuple'>
# 1
# 2
# 3
# 4

# We can unfold list into list of args
lst = ['red', 'green', 'blue']
printer(lst)


# <class 'tuple'>
# red
# green
# blue

def caller1(func, params):
    return func(*params)  # pass variable number of args to another function


# Variable num args and dict
def printer2(**kv_args):
    type(kv_args)  # <class 'dict'>
    for k, v in kv_args.items():
        print('{key} : {val}'.format(key=k, val=v))


printer2(a=10, b=5)
# <class 'dict'>
# a: 10
# b: 5

# unfold dict to kwargs

mydict = {'k1': 25, 'k2': 50}
printer2(**mydict)

# FILES

text_modes = ['r', 'w', 'a', 'r+']
binary_modes = ['br', 'bw', 'ba', 'br+']
f1 = open('filename', text_modes[1])

num_symbols_written = f1.write('Some multiline\nstring')
print(num_symbols_written)  # 21

f1.close()
# better way (will be closed):
with open('filename', 'r+') as f2:
    s = f2.write('tst')
# file will be closed anyway when program exits or by GC,
# but better to close as soon as we don't need it since descriptors can end

f3 = open('filename', 'r')
s2 = f3.read(2)  # 2 symbols
s1 = f3.read()  # entre file
f3.tell()  # 123
f3.read()  # ''
f3.seek(0)
f3.tell()  # 0

ln = f3.readline()
lst = f3.readlines()  # ['line1\n', 'line2\n',...]

f3.close()

import os

os.remove('filename')


# f.read() ->i/o error


# FUNCTIONAL PROGRAMMING

# Function is a 1st class object. It can be passed as argument, created inplace etc

def caller(func, args):
    return func(*args)


def printer(who, from_city):
    print("I'm {} from {}".format(who, from_city))


caller(printer, ['Vasya', 'Moscow'])


def get_multiplier():
    def multiplier_inner(m1, m2):
        return m1 * m2

    return multiplier_inner


multiplier = get_multiplier()
print(multiplier(2, 3))  # 6
print(multiplier.__name__)  # multiplier_inner


# Closure
def get_multiplier(by):
    def inner(a):
        return a * by

    return inner


multiplier_by_2 = get_multiplier(2)
print(multiplier_by_2(5))  # 10


# Library functions which simplify functional programming

# Apply function to all elements in container
def squarify(a):
    return a ** 2


results = map(squarify, range(5))
for item2 in results:
    print(item2)  # 0,1,4,9,16
# Second way
print(list(map(squarify, range(5))))  # [0, 1, 4, 9, 16]


# Filter by predicate
def is_positive(n):
    return n >= 0


print(list(filter(is_positive, range(-2, 3))))  # [0,1,2]

# Lambdas or anonymous functions (when we don't need separate function)
print(list(map(lambda x: x ** 2, range(10))))

print(type(lambda x: x ** 2))
# <class 'function'>

numbers = list(range(10))
print(list(map(str, numbers)))

# Interesting map usage:
day, month, year = map(int, '12-10-2017'.split('-'))

# functools has very useful helpers!
import functools


def mult(a, b):
    return a * b


print(functools.reduce(mult, [1, 3, 5, 7, 8]))
# mult(1,3)=3
# mult(3,5)=15
# mult(15,7)=105
# mult(105,8)=840
# 840

# second way
print(functools.reduce(lambda a, b: a * b, [1, 3, 5, 7, 8]))


def greeter(person, greeting):
    print('{}, {}!'.format(greeting, person))


hier = functools.partial(greeter, greeting='Hi')
helloer = functools.partial(greeter, greeting='Hello')
hier('Vasya')
helloer('Ivan Ivanovich')

# List comprehensions: a bit faster than regular loop, as well as shorter
# Can be used instead of map and filter
squares = [x ** 2 for x in range(10)]
print(squares)
even_list = [x for x in range(20) if x % 2 == 0]
print(even_list)

# Dict and set comprehensions in same way
num_to_str = {num: str(num) for num in range(10)}
print(list(num_to_str.items()))

even_set = {x for x in range(10) if x % 2 == 0}
print(list(even_set))

# Type of comprehension is generator
print(type(x for x in range(3)))
# <class 'generator'>

# zip - join sequences
numbers = list(range(5))
squares = [x ** 2 for x in numbers]
for tpl in zip(numbers, squares):
    print(tpl)
# (0,0) (1,1) (2,4) (3,9 (4,16)

print(list(zip(
    filter(bool, range(3)),
    [x for x in range(3) if x]
)))


# (1,1) (2,2)


# DECORATORS

# Decorator is function which accepts function and returns function
# Used to modify function(s) behavior

# Simplest decorator - return same function
def decorator1(func):
    return func


# Syntactic sugar:
@decorator1
def decorated():
    print('hello')


# It is equal to:
decorated = decorator1(decorated)


# Decorator which redefines function
def decorator2(func):
    def new_func():
        pass

    return new_func


@decorator2
def decorated2():
    print('hello')


# same as decorated2 = decorator2(decorated2)
print(decorated2.__name__)


# new_func

# Decorate generic function - write result to logfile
def logger(func):
    @functools.wraps(func)  # this is required to save original function name
    def wrapped(*args, **kwargs):  # handle any arguments, args should come before kwargs (positional before named)
        result = func(*args, **kwargs)
        with open('log.txt', 'w') as f:
            f.write(str(result))
        return result  # preserves function behavior - keeps return value for function

    return wrapped


@logger
def summator(num_list):
    return sum(num_list)


print('Summator: {}'.format(summator([1, 2, 3, 4])))  # 10
print(summator.__name__)  # summator - because of functools.wraps call


# Decorator with parameter - custom filename
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


# Apply two decorators:
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


# Inside first_decorator product
# Inside second_decorator product
# Finally called...

# Useful example of 2 decorators:
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


# <b><i>hello world</i></b>


# GENERATORS

# It is a function that contains operator yield

# Generator allows to store function state and return to it every time

# This particular generator doesn't store all range in memory, just stores state
def even_range(start, end):
    cur = start
    while cur < end:
        yield cur
        cur += 2


print(list(even_range(2, 15)))

# another way to iterate:
ranger = even_range(2, 5)
print(next(ranger))
print(next(ranger))


# print(next(ranger)) #-> error, out-of-range

# Useful example
def fibonacci(fnumber):
    a = b = 1
    for _ in range(fnumber):
        yield a
        a, b = b, a + b


for num in fibonacci(10):
    print(num)

# CLASSES

num = 13
print(type(num))  # <class 'int'>

print(isinstance(num, int))  # True
print(isinstance(num, float))  # False


class Robot:
    pass


print(dir(Robot))  # ['__class__', '__delattr__', '__dict__', '__doc__', '__init__', ...]
robot = Robot()
print(robot)  # <__main__.Robot object at 0x10ea82b0>


# Operate user objects as built-in:
class MyPlanet:
    pass


solarsystem = []
for _ in range(8):
    planet = MyPlanet()
    solarsystem.append(planet)

# Object is HASHABLE!
solar_system = {}
for i6 in range(8):
    planet = MyPlanet()
    solar_system[planet] = i6


# Constructors

class Planet:
    def __init__(self, name):
        self.name = name


earth = Planet("Earth")
print(earth.name)  # Earth
print(earth)  # <class 'Planet'>


class Planet2:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name  # print will print this string


print(earth)  # Earth
# but:
lst2 = [Planet2('Mars'), Planet2('Venus')]
print(lst2)  # [<__main__.Planet2 object...


class Planet3:
    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return 'Planet ' + self.name


lst3 = [Planet3('Mars'), Planet3('Venus')]
print(lst3)  # ['Planet Mars', ...]


# Class attributes (same as static members in C++)
class Planet4:
    count = 0

    def __init__(self, name, population=None):
        self.name = name
        self.population = population or []
        Planet4.count += 1


earth = Planet4("Earth")
mars = Planet4("Mars")
print(Planet4.count)  # 2
print(mars.count)  # 2 - also valid


# Destructor
class Human:
    def __del__(self):
        print("Goodbye!")


human = Human()
del human  # Goodbye!
# But better to do some cleanup (close file etc) explicitly in methods because there
# is not guarantee that del will be called

print(earth.__dict__)  # {'name' : Earth, 'population' : [] }

# Adding new member:
earth.mass = 5.97e24
print(earth.__dict__)  # {'name' : Earth, 'population' : [], 'mass' : 5.97e24 }
# Builtin types omit capability to add new member as an optimization
# Via __slots__, you can also prevent this on user-defined classes.
# But this is merely a space optimization (no need for a dictionary for every object), not a correctness thing.
# Theoretical base is here:
# https://stackoverflow.com/questions/12569018/why-is-adding-attributes-to-an-already-instantiated-object-allowed


# But trying to access non-existing member will fail:
# print(earth.radius) #'Planet4' object has no attribute 'radius'
# print(mars.mass) #Also fails!

# Check attr exists:
if hasattr(earth, 'weight'):
    print(earth.weight)
else:
    print('No attr weight in object earth!')
if hasattr(earth, 'mass'):
    print(earth.mass)


# Constructor:
class Planet5:
    def __new__(cls, *args, **kwargs):
        print('__new__ called')
        obj = super().__new__(cls)
        return obj

    def __init__(self, name):
        print("__init__ called")
        self.name = name


earth5 = Planet5('Earth')
# __new__ called
# __init__ called
# This call is equal to:

earth52 = Planet5.__new__(Planet5, 'Earth')
if isinstance(earth52, Planet5):
    Planet5.__init__(earth52, 'Earth')


# Convention for private members - name with _:
class Human1:
    def _say(self, text):
        print(text)


# But it is possible to access any class member:
hm = Human1()
# hm._say('hi!')  # Ok


# @classmethod - returns class instance
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

# Example of @classmethod from library:
dct = dict.fromkeys("12345")


# @staticmethod
class Car:

    def __init__(self, num_whells):
        self.num_whells = num_whells

    @staticmethod
    def is_valid_num_whells(num_whells):
        return num_whells == 4


print(Car.is_valid_num_whells(3))


# @property
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


# Shorter way if we need only reader
class Robot2:
    def __init__(self, power):
        self._power = power

    @property
    def power(self):
        # some optional calculations
        return self._power


# Inheritance
class Pet:
    def __init__(self, name=None):
        self.name = name or 'Pet'


class Dog(Pet):
    def __init__(self, name, breed=None):
        super().__init__(name)
        self.breed = breed

    def say(self):
        return f'{self.name}, waw!'


# Multiple inheritance:

class Baby:
    def __init__(self):
        self.__size = 'small'


class SmallDog(Dog, Baby):
    def __init__(self, name, breed=None):
        # Explicit specification
        super(SmallDog, self).__init__(name)


# Test for predecessor:
print(issubclass(Dog, object))  # True: any class inherited from object!
print(issubclass(int, object))  # True
print(issubclass(SmallDog, Dog))  # True
print(issubclass(Dog, int))  # False

# Test if object has class:
smalldog = SmallDog('Black')
print(isinstance(smalldog, Dog))  # True
print(isinstance(smalldog, SmallDog))  # True
print(isinstance(smalldog, int))  # False

# investigate class hierarchy:
print(SmallDog.__mro__)  # Member Resolution Order (order in which Python searches for member)

# Details about multiple inheritance are here: https://docs.python.org/3/tutorial/classes.html#inheritance


# EXCEPTIONS

# Inherit exceptions from Exception class, not BaseException
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
    1 / 0
except:  # catch all exception types
    print("Divide by zero")

# The above can be bad if we press Ctrl-C inside try block since KeyboardInterrupt will also be handled
# try:
# n = input("Enter number")
# except:
# print("Wrong number")

try:
    lst = [1, 2]
    print(lst[4])
except LookupError:  # catch Exception successors (KeyError, IndexError)
    print('LookupError')

try:
    n1 = 1 / 2
except:
    print("Some error")
else:
    print(n1)

# Several exception types:
try:
    n2 = 1 / 0
except ValueError:
    print('ValueError')
except ZeroDivisionError:
    print('ZeroDivisionError')

try:
    f5 = open('/etc/hosts')
    print(1 / 0)
except Exception:
    print('Some error')
finally:
    print("We're in 'finally' block")

# Access exception info
try:
    f5 = open('etc/hosts1')
except OSError as os_ex:
    print(os_ex.errno, ':', os_ex.strerror)

# Raising exception and reading args
try:
    fname = '/etc/kadabra'
    if not os.path.exists(fname):
        raise ValueError("File doesn't exist", fname, 'SomeArg')
    f6 = open(fname)
except ValueError as ve:
    msg, fname = ve.args[0], ve.args[1]
    print(msg, fname, ve.args)

# Get trace after exception:
import traceback

try:
    with open('/file/not/found') as f:
        content = f.read()
except OSError as err:
    trace = traceback.format_exc()
    print(trace)

# Passing exception to the next level:
try:
    1 / 0
except ZeroDivisionError as zd_ex:
    print(zd_ex.args)
    # raise
    # or:
    # raise Exception from ex #The above exception was the direct cause of the following exception:

# Assert

try:
    assert 1 == 0, "1 != 0"
except AssertionError as ae:
    print(ae.args[0])
# In real life we don't need to handle AssertionError
# Instead we can disable them by specifying flag -O to Python

# Exception adds valuable performance cost

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


# MAGIC METHODS

# __init__, ___new__, __str__ already described above

# __hash__, __eq__

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

print(john == jack)  # True

print(hash(john))  # 125274383719749823
print(hash(jack))  # 125274383719749823


# __getattr__: defines behavior when attribute not found, called only when attr not found
# __getattribute__: called always when we access to attribute. We can, e.g. log access to attribute

class Researcher:
    def __getattr__(self, name):
        return 'Nothing found'

    def __getattribute__(self, name):
        print('Looking for {}'.format(name))  # override
        return object.__getattribute__(self, name)  # call original __getattribute__


researcher = Researcher()

print(researcher.attr)
# Looking for attr
# Nothing found
researcher.myattr = 1
print(researcher.myattr)


# Looking for method
# 1

# __setattr__
class Ignorant:
    def __setattr__(self, name, value):
        print('Not gonna set {}'.format(name))


ignorant = Ignorant()

ignorant.myattr = '3.14'


# Not gonna set myattr

# print(obj.myattr)
# AttributeError: 'Ignorant' object has no attribute 'myattr'

# __delattr__
# We can delete or not delete attribute in this method

class Deleter:
    def __delattr__(self, item):
        value = getattr(self, item)
        print(f'Goodbye {item}, you were {value}')
        object.__delattr__(self, item)


deleter = Deleter()
deleter.myattr = 10
del deleter.myattr


# Goodbye myattr, you were 10

# __call__
# Called when class is called

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


useless_func()  # will do nothing but will log 'Oh yes!' to a file

# __add__, __sub__
# Redefine +/-
import random


class NoisyInt:
    def __init__(self, val):
        self.val = val

    def __add__(self, other):
        noise = random.randint(1, 10)
        return self.val + other.val + noise


an = NoisyInt(10)
bn = NoisyInt(20)
for _ in range(3):
    print(an + bn)


# 40
# 39
# 35

# __getitem__, __setitem__
# Defines object behavior during access by index
# Defines object behavior during setting value by index
class PascalArray:
    def __init__(self, other_list=None):
        self.lst = other_list or []

    def __getitem__(self, key):
        return self.lst[key - 1]

    def __setitem__(self, key, value):
        self.lst[key - 1] = value


orig_lst = [1, 3, 5, 7, 9]
pascal_array = PascalArray(orig_lst)
pascal_array[4] = 8
print(pascal_array[3], pascal_array[4])  # 5, 8

# ITERATORS

for number in range(5):
    print(number)

for letter in 'python':
    print(letter)

for item1 in [1, 2, 3]:
    print(item1)

iterator = iter([1, 2, 3])
print(next(iterator))
print(next(iterator))
print(next(iterator))


# print(next(iterator)) raises StopIteration that means we should e.g. break for loop


# Writing own iterator: implement __iter__ and __next__
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


for num in SquareIter(1, 4):
    print(num)


# 1,4,9


# CONTEXT MANAGERS (with...)

# To define own context manager we need to redefine 2 magic methods __enter__ and __exit__

class open_file:
    def __init__(self, filename, mode):
        self.f = open(filename, mode)

    def __enter__(self):
        return self.f  # for using "as f" if needed

    def __exit__(self, *args):
        self.f.close()


with open_file('log.txt', 'w') as f:
    f.write('Hello from context manager')

os.remove('log.txt')


# Context managers are useful for exceptions
class suppress_exception:
    def __init__(self, exc_type):
        self.exc_type = exc_type

    def __enter__(self):
        return
        # pass also valid

    def __exit__(self, exc_type, exc_val, trackback):
        if exc_type == self.exc_type:
            print('Nothing happened')
            return True  # mandatory to not re-throw exception


with suppress_exception(ZeroDivisionError):
    a17 = 1 / 0
    # Nothing happened

# Exception suppressing already exists in library
import contextlib

with contextlib.suppress(ValueError):
    raise ValueError

# Useful application:
import time


class timer:
    def __init__(self):
        self.start = time.time()

    def get_elapsed(self):
        return time.time() - self.start

    def __enter__(self):
        return self

    def __exit__(self, *args):
        print('Elapsed: {}'.format(t.get_elapsed()))


with timer() as t:
    time.sleep(0.1)
    print('Current: {}'.format(t.get_elapsed()))
    time.sleep(0.1)


# DESCRIPTORS
# Allow to work classes, objects, methods

# Contain up to 3 methods:
class Descriptor:  # name can be any
    def __get__(self, obj, obj_type):
        print('get')

    def __set__(self, obj, obj_value):
        print('set')

    def __delete__(self, obj):
        print('delete')


class MyClass:
    attr = Descriptor()


instance = MyClass()
print(instance.attr)  # get
instance.attr = 5  # set


# del instance.attr #delete

# Descriptors allow to redefine classes behavior invisibly for users
# Example:
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
print(myval.attr)  # 100


# Example: descriptor which saves all assignments to file

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
bobs_account.amount = 150  # This change is logged to a file


# Bound methods/unbound methods (functions):
class Class:
    def __init__(self):
        self.a = 5

    def method(self):
        print(self.a)


class_instance = Class()

print(class_instance.method)  # <bound method Class.method of <__main__.Class object at 0x0000000002DD9C50>>
print(Class.method)  # <function Class.method at 0x0000000002DE6620>
# Same method returns different objects depending on the way it accessed
class_instance.method()  # 5
Class.method(class_instance)  # 5


# Property, ClassMethod and StaticMethod are descriptors


# SLOTS

# Limits the possible class attributes with some predefined dict

class Class1:
    __slots__ = ['name']

    def __init__(self):
        self.name = 'Vasya'


obj1 = Class1()


# obj1.familyname = 'Petrov' #AttributeError: 'Class1' object has no attribute 'familyname'

# Slots implemented as descriptors for each attribute


# META CLASSES

# Class which creates other classes

class Class2:
    pass


cls2 = Class2()

print(type(cls2))  # <class '__main__.Class2'>
print(type(Class2))  # 'type' - it creates our class. 'type' is metaclass - it creates other classes
print(type(type))  # 'type' - recursive closure

# Creation and inheritance are different:
print(issubclass(Class2, type))  # False
print(issubclass(Class2, object))  # True

# Create class on-the-fly:
NewClass = type('NewClass', (), {})  # class without parents and attrs
print(NewClass)  # <class '__main__.NewClass'>
print(NewClass())  # <__main__.NewClass object at 0x0000000003931A90>


# Create our own meta-class
class Meta(type):
    def __new__(mcs, name, parents, attrs):
        print('Creating {}'.format(name))

        if 'class_id' not in attrs:
            attrs['class_id'] = name.lower()

        return super().__new__(mcs, name, parents, attrs)


class A(metaclass=Meta):
    pass


# Creating A


class Meta2(type):
    def __init__(cls, name, bases, attrs):
        print('Initializing — {}'.format(name))

        if not hasattr(cls, 'registry'):
            cls.registry = {}
        else:
            cls.registry[name.lower()] = cls

        super().__init__(name, bases, attrs)


class Base(metaclass=Meta2):
    pass


class A2(Base):
    pass


class B(Base):
    pass


# Initializing — Base
# Initializing — A2
# Initializing — B
print(Base.registry)  # {'a': <class '__main__.A'>, 'b': <class '__main__.B'>}
print(Base.__subclasses__())  # [<class '__main__.A'>, <class '__main__.B'>]

# ABSTRACT METHODS

from abc import ABCMeta, abstractmethod


class Sender(metaclass=ABCMeta):
    @abstractmethod
    def send(self):
        """Do something"""


class Child(Sender):
    pass


# Child()
# TypeError: Can't instantiate abstract class Child with abstract methods send
class Child2(Sender):
    def send(self):
        print('Sending')


print(Child2())  # <__main__.Child2 at 0x110cfa860>


# Better to use the following form of abstract class:
class PythonWay:
    def send(self):
        raise NotImplementedError


# DEBUGGING

def f():
    # import pdb
    # pdb.set_trace()
    # type : step, next, ll, b [line], continue, p, ..., q, help, help [command]
    pass


f()

# Another way:
# python -m pdb <code.py>


# UNITTESTS

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


# To run:
# >> python3 - m unittest test_python.py


# Another example with setUp and mock

import urllib.request


class Asteroid:
    BASE_API_URL = 'https://api.nasa.gov/neo/rest/v1/neo/{}?api_key=DEMO_KEY'

    def __init__(self, spk_id):
        self.api_url = self.BASE_API_URL.format(spk_id)

    def get_data(self):
        response = urllib.request.urlopen(self.api_url).read()
        response = response.decode()
        return json.loads(response)

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
# Name: 99942 Apophis (2004 MN4)
# Diameter: 682m

import json
import unittest
from unittest.mock import patch


class TestAsteroid(unittest.TestCase):
    def setUp(self):  # Method runs before each test case. Also there is a tearDown method
        self.asteroid = Asteroid(2099942)

    def mocked_get_data(self):
        with open('apophis_fixture.txt') as f:  # file contains json downloaded before
            return json.loads(f.read())

    @patch('asteroid.Asteroid.get_data', mocked_get_data)  # Decorator replaces given method with mock
    def test_name(self):
        self.assertEqual(self.asteroid.name, '99942 Apophis (2004 MN4)')

    @patch('asteroid.Asteroid.get_data', mocked_get_data)
    def test_diameter(self):
        self.assertEqual(self.asteroid.diameter, 682)


print(f'Date: {apophis.closest_approach["date"]}')
print(f'Distance: {apophis.closest_approach["distance"]:.2} LD')

# PROCESSES
# Commands: top, ps aux | grep <your_process>, lsof (show open files, including stdin, stdout, stderr - 0,1,2), strace -p <pid> (system calls)

import os

print(os.getpid())

# Fork - creates copy of parent process, with all resources and same code
# This code works in *nix:
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

# Threads

from threading import Thread


def ft(name):
    print('Hello from thread,', name)


thread1 = Thread(target=ft, args=('Bob',))
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

# Thread pool

from concurrent.futures import ThreadPoolExecutor, as_completed


def ftp(a):
    return a * a


# .shutdown() on exit
with ThreadPoolExecutor(max_workers=3) as pool:
    results = [pool.submit(ftp, i) for i in range(10)]

    for fut1 in as_completed(results):
        print(fut1.result())
# results will be mixed in order (4, 1, 0, 9, 25...)


# Queues - preferred way for synchronization instead of locks
from queue import Queue
from threading import Thread


def tfq(q, n):
    while True:
        q_item = q.get()
        if q_item is None:  # There is no way to close process in Python (to avoid inconsistent state) so we're putting special value to queue
            break
        print("Process data in thread {}: get item {}".format(n, q_item))


qu = Queue(5)  # max number of elements
th1 = Thread(target=tfq, args=(qu, 1))
th2 = Thread(target=tfq, args=(qu, 2))
th1.start()
th2.start()

for i7 in range(50):
    qu.put(i7)  # if size is already 5 the "put" blocks until item is popped from queue

qu.put(None)
qu.put(None)

th1.join()
th2.join()

# Locks

import threading


# With context manager:
class Point:
    def __init__(self):
        self.mutex = threading.RLock()
        self.x = 0
        self.y = 0

    def get(self):
        with self.mutex:
            return self.x, self.y

    def set(self, x, y):
        with self.mutex:
            self.x, self.y = x, y


# Without context manager:

mutex1 = threading.RLock()
mutex2 = threading.RLock()


def foo():
    try:
        mutex1.acquire()
        mutex2.acquire()
        print('Acquire')
    finally:
        mutex1.release()  # Can cause deadlock if called from different threads since we release in incorrect order
        mutex2.release()
        print('Release')


threads = [Thread(target=foo) for _ in range(10)]

for td in threads:
    td.start()

for td in threads:
    td.join()


# Conditional variables

class MyQueue:

    def __init__(self, size=5):
        self._queue = []
        self._size = size
        self._mutex = threading.RLock()
        self._empty = threading.Condition(
            self._mutex)  # There is default lock object for CV, but for dependent CVs we have to use common lock object
        self._full = threading.Condition(self._mutex)

    def put(self, item):
        with self._full:
            print('trying to push element')
            while len(self._queue) >= self._size:
                print('queue is full, waiting')
                self._full.wait()  # wait until queue is ready to accept new item
            print('element pushed')
            self._queue.append(item)
            self._empty.notify()  # notify all other waiting threads that there is item in queue

    def get(self):
        with self._empty:
            print('trying to get element')
            while len(self._queue) == 0:
                print('queue is empty, waiting')
                self._empty.wait()  # wait for element
            print('element popped')
            ret = self._queue.pop(0)
            self._full.notify()  # notify all threads which wait trying to put element into a full queue
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

# GIL (Global Interpreter Lock)

# Python's GIL is intended to serialize access to interpreter internals from different threads
# On multi-core systems, it means that multiple threads can't effectively make use of multiple cores.
# Note that Python's GIL is only really an issue for CPython, the reference implementation. Jython and IronPython don't have a GIL.
# C extension writers need to release the GIL when their extensions do blocking I/O, so that other threads in the Python process get a chance to run.

# It is better to execute CPU-bound tasks sequentially
# It is better to execute I/O-bound tasks or system calls simultaneously in threads

# GIL implemented as threading.Lock (non-recursive)
# Every thread slips for 5 ms waiting for releasing GIL

# CPU-bound example:

import time


def cpu_bound(count=3_000_000):
    while count > 0:
        count -= 1


t0 = time.time()
cpu_bound()
cpu_bound()
print('Sequential time: ', time.time() - t0)

t0 = time.time()
tcpu1 = Thread(target=cpu_bound())
tcpu2 = Thread(target=cpu_bound())
tcpu1.start()
tcpu2.start()
tcpu1.join()
tcpu2.join()
print('Parallel time: ', time.time() - t0)

# Sequential time:  1.4420826435089111
# Parallel time:  1.9200959205627441

# How thread runs?

"""

a      r      a            r              a          r    a
  run  |------|    run     |--------------|   run    |----| run
------>|  IO  |----------->|      IO      |--------->| IO |----->
       |------|            |--------------|          |----|
a      r      a            r              a          r    a

a - acquire GIL
r - release GIL

"""

# SOCKETS
# Sockets are cross-platform mechanism for data exchange between processes which can run on different hosts and can be written on different languages
# They are implemented via system calls

# Server


def run_echo_server():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(('127.0.0.1',
               10001))  # Max port is 65535. Address 127.0.0.1 means server listens only local connections. Empty '' or '0.0.0.0' means any interface
    sock.listen(
        socket.SOMAXCONN)  # Parameter means size of queue for incoming connections. If overflow - "connection refused" is returned to client
    conn, addr = sock.accept()  # Blocks until client connects. conn is duplex channel which supports read (recv) and write (send)
    while True:
        data = conn.recv(1024)  # 1024 is a buffer size
        if not data:  # client closed connection
            break
        # process data
        print(data.decode('utf-8'))
    conn.close()
    sock.close()


# Client

def run_client():
    sock = socket.socket()  # socket.AF_INET, socket.SOCK_STREAM are defaults
    sock.bind(('127.0.0.1', 10001))
    # Shorter form of 2 LOCs above:
    # sock = socket.create_connection(('127.0.0.1', 10001))
    sock.sendall('ping'.encode('utf-8'))
    # or: sock.sendall(b'ping')
    sock.close()


# Using context managers to not forget to close connection and socket

def run_echo_server_with_cm():
    with socket.socket() as sock:
        sock.bind(('', 10001))  # '0.0.0.0' or '' means any interface
        sock.listen()
        while True:
            conn, addr = sock.accept()
            with conn:
                while True:
                    data = conn.recv(1024)
                    if not data:
                        break
                    print(data.decode('utf-8'))


def run_client_with_cm():
    with socket.create_connection(('127.0.0.1', 10001)) as sock:
        sock.sendall(b'ping')


# Errors processing with sockets

def run_server_with_cm_and_error_handling():
    with socket.socket() as sock:
        sock.bind(('', 10001))
        sock.listen()
        while True:
            conn, addr = sock.accept()
            conn.settimeout(
                5)  # timeout = None | 0 | >0. None means blocking forever until receive data (default), 0 - non-clocking mode
            with conn:
                while True:
                    try:
                        data = conn.recv(1024)
                    except socket.timeout:
                        print('Close connection by timeout')
                        break
                    if not data:
                        break
                    print(data.decode('utf-8'))


def run_client_with_cm_and_error_handling():
    with socket.create_connection(('127.0.0.1', 10001),
                                  5) as sock:  # 5 is connect timeout, in case of exceeded just try to reconnect
        sock.settimeout(2)  # 2 is socket read timeout - timeout for all operations with opened socket
        try:
            sock.sendall(b'ping')
        except socket.timeout:
            print('Send data timeout')
        except socket.error as ex:
            print('Send data error', ex)


# Multiple connections handling

# sock.accept() blocks all other clients except one

# It is possible to create new process to handle new connection but resources required to create process are
# greater than resources required to handle connection, especially if we have 1000s connections.
# If there are few connections - it is normal solution which helps to utilize all CPUs.
# Another way is to create threads for new connections, but there are GIL limitations.

def process_request(conn, addr):
    print('Connected client', addr)
    with conn:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            print(data.decode('utf-8'))


def run_server_multi_connections_threads():
    with socket.socket() as sock:
        sock.bind(('', 10001))
        sock.listen()
        while True:
            conn, addr = sock.accept()  # blocks all other clients except one
            th = threading.Thread(target=process_request, args=(conn, addr))
            th.start()  # main thread will continue to accept new connections after starting this thread
            # somewhere later we must call th.join()


# Better way is to use processes and threads together. But in this case call to socket.accept()
# will awake all our processes and it adds some overhead

import threading
import multiprocessing


def worker(sock):
    while True:
        conn, addr = sock.accept()
        print('pid: ', os.getpid())
        th = threading.Thread(target=process_request, args=(conn, addr))
        th.start()


def run_server_multi_connections_processes_and_threads():
    with socket.socket() as sock:
        sock.bind(('', 10001))
        sock.listen()
        workers_count = 3
        workers_list = [multiprocessing.Process(target=worker, args=(sock,)) for _ in range(workers_count)]
        for w in workers_list:
            w.start()
        for w in workers_list:
            w.join()


# "PARALLEL" CODE EXECUTION IN ONE THREAD (NON-BLOCKING I/O, MULTIPLEXING) - no process/thread overhead

# SELECT

import socket


def non_blocking_server():
    sock = socket.socket()
    sock.bind(('', 10001))
    sock.listen()

    conn1, addr1, = sock.accept()
    conn2, addr2, = sock.accept()

    # How to process requests for conn1 and conn2 simultaneously but without processes/threads

    # Switch to non-blocking mode
    # If we then try to call conn.recv but there is not data - the call will not block but will return system error about data absence
    conn1.setblocking(False)  # equal to settimeout(0.0)
    conn2.setblocking(False)

    # How to know which sockets are ready for reading and which are ready for writing?
    # In Linux:
    """
    epoll = select.epoll()
    epoll.register(conn1.fileno(), select.EPOLLIN | select.EPOLLOUT)
    epoll.register(conn2.fileno(), select.EPOLLIN | select.EPOLLOUT)

    conn_map = {
        conn1.fileno(): conn1,
        conn2.fileno(): conn2,
        }
    
    while True:
        events = epoll.poll(1)
    
    for fileno, event in events:
        if event & select.EPOLLIN:
            # Read from socket
            data=conn_map[fileno].recv(1024)
            print(data.decode("utf8"))
        elif event & select.EPOLLOUT:
            # Write to socket
            conn_map[fileno].send("pong".encode("utf8"))        
    """

    # In Windows
    """
    connList = [conn1.fileno(), conn1.fileno()]
    sel = select.select(rlist = connList , wlist = connList , xlist = connList) #In Linux there will be select.epoll
    ...
    See:
    http://steelkiwi.com/blog/working-tcp-sockets/
    """


# Framework hides all logic with select:
# Twisted, callback api
# https://twistedmatrix.com
# Gevent, greenlet, stackless python
# http://www.gevent.org/
# Tornado, generators api
# http://www.tornadoweb.org
# Asyncio, mainstream
# https://docs.python.org/3/library/asyncio.html


# ITERATORS VS GENERATORS

# Iterator:

class MyRangeIterator:
    def __init__(self, top):
        self.top = top
        self.current = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.current >= self.top:
            raise StopIteration
        current = self.current
        self.current += 1
        return current


mycounter = MyRangeIterator(3)
print(mycounter)
# <__main__.MyRangeIterator object at 0x035E4370>

for it in mycounter:  # __iter__ called, then __next__ called each round
    print(it)


# 0 1 2

# Generator

def my_range_generator(top):
    current = 0  # just local variable, no state (it is saved on stack during yield)
    while current < top:
        yield current  # yield makes function generator, it stops flow, saves stack frame and returns value. Next time when called it restores stack and continues
        current += 1


mygenerator = my_range_generator(3)  # this doesn't call function, but creates object
print(mygenerator)
# <generator object my_range_generator at 0x03C82C30>
for gen in mygenerator:
    print(gen)


# 0 1 2

# COROUTINES

# Generators produce values, coroutines consume values


# Coroutine example:

def grep(pattern):
    print('Start grep')
    while True:
        line = yield  # difference from generator: here function suspends and waits for data through method 'send'
        if pattern in line:
            print(line)


gr = grep('python')  # coroutine created (this is also generator)
next(gr)  # g.send(None) - starts coroutine, it runs until yield and then flow returns to main (function stack with all local variables is saved) until we send something to coroutine
# Start grep
gr.send('golang is better')
gr.send('python is simpler')


# python is simpler


# How to stop running coroutine

def grep_stopable(pattern):
    try:
        while True:
            line = yield
            if pattern in line:
                print(line)
    except GeneratorExit:
        print('Coroutine stopped')


grs = grep_stopable('python')
grs.send(None)
grs.send('python is great!')
grs.close()  # throws GeneratorExit exception at the place here coroutine suspended at this moment

# Passing exception to coroutine (it also stops execution)

grs = grep_stopable('python')
next(grs)  # or g.send(None)
grs.send('python is excellent')
try:
    grs.throw(RuntimeError, 'Something wrong')
except RuntimeError:
    print('Coroutine stopped by exception')


# Call one coroutine from another

def grep_python_coroutine():
    g = grep('python')
    next(g)
    g.send('python is great!')
    g.close()


gpc = grep_python_coroutine()
print(gpc)


# None (g is not coroutine, but regular function)

def grep_python_coroutine2():
    g = grep('python')
    yield from g  # delegating the call


gpc = grep_python_coroutine2()
print(gpc)
# <generator object grep_python_coroutine2 at 0x03E4D150>
gpc.send(None)
gpc.send('python wow!')
gpc.close()


# Using 'yield from' in regular generators:

def chain(x_iterable, y_iterable):
    yield from x_iterable
    yield from y_iterable


# Another way to do the same:
def the_same_chain(x_iterable, y_iterable):
    for x in x_iterable:
        yield x
    for y in y_iterable:
        yield y


a1 = [1, 2, 3]
b1 = (4, 5)

for x in chain(a1, b1):
    print(x)
# 1,2,3,4,5
for x in the_same_chain(a1, b1):
    print(x)
# 1,2,3,4,5


# ASYNCIO - responsible for non-blocking i/o. Base is generators and coroutines. Part of Python library. No callbacks.

# Asyncio Hello, world!

import asyncio


@asyncio.coroutine
def hello_world():
    for _ in range(3):
        print('Hello, world!')
        yield from asyncio.sleep(
            0.5)  # this is special sleep which suspends coroutine and allows other coroutines to work


event_loop = asyncio.get_event_loop()
print(event_loop)
# <_WindowsSelectorEventLoop running=False closed=False debug=False>
event_loop.run_until_complete(hello_world())


# loop.close() we don't close it now as it is reused below (see https://stackoverflow.com/questions/43646768/cant-create-new-event-loop-after-calling-loop-close-asyncio-get-event-loop-in-p)

# Event loop is the main concept in asyncio.
# Event loop is a kind of scheduler of tasks (coroutines) which are running in it. It is responsible for i/o,
# manages signals, network operations, it switches context between coroutines.
# It is especially effective if some coroutine waits long on i/o - event loop can easily switch to another coroutine.
# We can run only coroutines in event loop. Synchronous functions can be executed with some tricks (see below) as they block the flow and event loop can't switch context.
# Event loop runs all coroutines sequentially and switches context between them

# New syntax starting from Python 3.5 and PEP 492: async and await

async def hello_world2():
    for _ in range(3):
        print('Hello, world2!')
        await asyncio.sleep(0.5)


# 'async' guarantees that function is a coroutine (comparing to @asyncio.coroutine which doesn't guarantee this
# we can't use yield from inside, but we must use await

event_loop2 = asyncio.get_event_loop()
event_loop2.run_until_complete(hello_world2())


# loop.close()

# Simple TCP server on asyncio
# This is linear and very clear code, no GIL issues etc.

async def handle_echo(reader, writer):
    data = await reader.read(1024)
    message = data.decode()
    addr = writer.get_extra_info('peername')
    print(f'received {message} from {addr}')
    writer.close()


def start_server():
    loop = asyncio.get_event_loop()
    coro = asyncio.start_server(handle_echo, '127.0.0.1', 10001, loop=loop)
    server = loop.run_until_complete(coro)
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass
    server.close()
    loop.run_until_complete(server.wait_closed())
    loop.close()


# Client for server above:

async def tcp_echo_client(message, loop):
    reader, writer = await asyncio.open_connection('127.0.0.1', 10001, loop=loop)
    print('send %r' % message)
    writer.write(message.encode())
    writer.close()


def start_client():
    loop = asyncio.get_event_loop()
    message = 'Hello, world!'
    loop.run_until_complete(tcp_echo_client(message, loop))
    loop.close()


# It is possible to create several clients, connect to several servers etc. And it will be without threads.


# asyncio.Future (analogue of concurrent.futures.Future)
# Future is the object which is still running

async def slow_operation(fut):
    await asyncio.sleep(1)
    fut.set_result('Future is done!')


event_loop3 = asyncio.get_event_loop()
future1 = asyncio.Future()
asyncio.ensure_future(slow_operation(future1))
event_loop3.run_until_complete(future1)
print(future1.result())


# Future is done!
# loop.close()

# Run several coroutines inside single event loop - asyncio.Task (inherits from asyncio.Future)

async def sleep_task(num):
    for i in range(5):
        print(f'process task: {num} iter: {i}')
        await asyncio.sleep(1)
    return num


# ensure_future or create_task
event_loop4 = asyncio.get_event_loop()
task_list = [event_loop4.create_task(sleep_task(i)) for i in range(2)]

# 3 ways to run:
event_loop4.run_until_complete(asyncio.wait(task_list))
event_loop4.run_until_complete(event_loop4.create_task(sleep_task(3)))
event_loop4.run_until_complete(asyncio.gather(
    sleep_task(10),
    sleep_task(20),
))

# How to run synchronous functions inside event loop?

from urllib.request import urlopen


# synchronous function:
def sync_get_url(url):
    return urlopen(url).read()


async def load_url(url, loop=None):
    future = loop.run_in_executor(None, sync_get_url, url)  # runs synchronous function in thread pool
    response = await future
    print(len(response))


event_loop5 = asyncio.get_event_loop()
event_loop5.run_until_complete(load_url('https://google.com', loop=event_loop5))

# There are several libs in asyncio: aiohttp, aiomysql, aiomcache (see https://github.com/aio-libs)
