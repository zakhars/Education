body_whl = '1,2,3'
body_length, body_width, body_height = 0.0,0.0,0.0
if body_whl != '':
    dimensions = body_whl.split(',')
    body_length, body_width, body_height = [float(dim) for dim in dimensions]

print(body_length, body_width, body_height)