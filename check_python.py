if __name__ == "__main__":
    import ctypes
    import threading
    import time

    import sys
    assert sys.version_info[:2] == (3, 7), 'Expected Python 3.7. Found: %s' % (sys.version_info[:2],)
    assert sys.maxsize > (2 ** 32), 'Expected 64 bit Python.'

    lib = ctypes.pydll.LoadLibrary("check_minhook_amd64.dll")
    print('Library loaded: %s' % (lib,))
    assert lib.PatchPyGILState_Ensure() == 0

    def target():
        i = 0
        while True:
            i += 1
            time.sleep(.1)
            if i % 5 == 0:
                print(threading.current_thread())

    t = threading.Thread(target=target)
    t.start()

    target()
