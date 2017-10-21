import asyncio

@asyncio.coroutine
def hello_world():
    for _ in range(3):
        print('Hello, world!')
        yield from asyncio.sleep(0.5) #this is special sleep which suspends coroutine and allows other coroutines to work

loop = asyncio.get_event_loop()
print(loop)
#<_WindowsSelectorEventLoop running=False closed=False debug=False>
loop.run_until_complete(hello_world())
print(loop)