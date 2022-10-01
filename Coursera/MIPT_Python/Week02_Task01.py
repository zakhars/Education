import sys
import argparse
import json
import os
import tempfile


if '--key' not in sys.argv or len(sys.argv) < 3:
    print('No key specified')
    sys.exit(-1)

key_name = sys.argv[2] if sys.argv[1] == '--key' else sys.argv[4]
val = None
if '--val' in sys.argv:
    val = sys.argv[2] if sys.argv[1] == '--val' else sys.argv[4]
wanna_store = (len(sys.argv) == 5)
storage_path = os.path.join(tempfile.gettempdir(), 'storage.data')

kv_dict = {}

if os.path.exists(storage_path):
    with open(storage_path, 'r') as f:
        kv_dict = json.loads(f.read())

if wanna_store:
    if key_name not in kv_dict:
        kv_dict[key_name] = []
    kv_dict[key_name].append(val)
    with open(storage_path, 'w') as f:
        f.write(json.dumps(kv_dict))
else:
    if kv_dict.get(key_name) is None:
        print('None')
    else:
        print(', '.join(kv_dict[key_name]))


# Teacher's solution:

storage_path = os.path.join(tempfile.gettempdir(), 'storage.data')


def clear():
    os.remove(storage_path)


def get_data():
    if not os.path.exists(storage_path):
        return {}

    with open(storage_path, 'r') as storage:
        raw_data = storage.read()
        if raw_data:
            return json.loads(raw_data)

        return {}


def put(key, value):
    data = get_data()
    if key in data:
        data[key].append(value)
    else:
        data[key] = [value]

    with open(storage_path, 'w') as storage:
        storage.write(json.dumps(data))


def get(key):
    data = get_data()
    return data.get(key)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--key', help='Key')
    parser.add_argument('--val', help='Value')
    parser.add_argument('--clear', action='store_true', help='Clear')

    args = parser.parse_args()

    if args.clear:
        clear()
    elif args.key and args.val:
        put(args.key, args.val)
    elif args.key:
        print(get(args.key))
    else:
        print('Wrong command')
