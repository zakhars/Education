import tempfile
import os
import uuid


class File:
    def __init__(self, filepath):
        self.filepath = filepath
        self.f = open(filepath, 'w+')

    def __add__(self, other):
        self.f.seek(0)
        other.f.seek(0)
        contents_sum = self.f.read() + other.f.read()
        new_filepath = os.path.join(tempfile.gettempdir(), 'storage.data')
        combined = File(new_filepath)
        combined.write(contents_sum)
        return combined

    def __iter__(self):
        self.f.seek(0)
        return self

    def __next__(self):
        ln = self.f.readline()
        if ln == '':
            raise StopIteration
        return ln

    def __str__(self):
        return self.filepath

    def write(self, ln):
        self.f.write(ln)
        self.f.flush()


f1 = File(r'd:\f1.txt')
f1.write('line1\nline2\n')
f2 = File(r'd:\f2.txt')
f2.write('line3\nline4\n')
f3 = f1 + f2
print(f3)
for line in f3:
    print(line)


# Teacher's solution

class File2:
    def __init__(self, path):
        self.path = path
        self.current_position = 0

        if not os.path.exists(self.path):
            open(self.path, 'w').close()

    def write(self, content):
        with open(self.path, 'w') as f:
            return f.write(content)

    def read(self):
        with open(self.path, 'r') as f:
            return f.read()

    def __add__(self, obj):
        new_path = os.path.join(
            os.path.dirname(self.path),
            str(uuid.uuid4().hex)
        )
        new_file = type(self)(new_path)
        new_file.write(self.read() + obj.read())

        return new_file

    def __str__(self):
        return self.path

    def __iter__(self):
        return self

    def __next__(self):
        with open(self.path, 'r') as f:
            f.seek(self.current_position)

            ln = f.readline()
            if not ln:
                self.current_position = 0
                raise StopIteration('EOF')

            self.current_position = f.tell()
            return ln
