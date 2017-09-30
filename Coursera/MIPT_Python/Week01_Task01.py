collections = ['set', 'list', 'dict']
for idx, c in enumerate(collections):
    print(idx, c)

collections.append('tuple')
collections += ['tuple'] #equal
print(collections)
