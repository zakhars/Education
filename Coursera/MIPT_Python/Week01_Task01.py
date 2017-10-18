collections_map = {
    'mutable' : [ 'list', 'set', 'dict' ],
    'immutable' : [ 'tuple', 'frozenset' ]
    }
print(collections_map['immutable'])

print('set' in collections_map) #searches in keys
print('elem' in collections_map.keys())
print('elem' in collections_map.values())
print(('elem', 'val') in collections_map.items())
