import ctypes
lib = ctypes.cdll.LoadLibrary('../libfoo.so')



class Result(ctypes.Structure):
    _fields_=[('ret_data', ctypes.c_ulonglong),
              ('ret_size', ctypes.c_ulong)]

lib.Foo_Struct.restype = ctypes.POINTER(Result)

class Foo(object):

    def __init__(self):
        self.obj = lib.Foo_new()

    #def set_result(self, result):
    #    self.result = result

    def bar(self):
        lib.Foo_bar(self.obj)

    def struct(self):
        return lib.Foo_Struct()

    def get_result(self, a, b, result):
        lib.Foo_get(self.obj, a, b, result)


f = Foo()
result = f.struct()

f.get_result(10, 10, result)

print(result.contents.ret_data, '     ', result.contents.ret_size)
