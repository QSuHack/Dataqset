import pyaes
import os
import hashlib


def szyfruj(nazwa_pliku_do_zaszyfrowania, klucz):
    file_in = open(nazwa_pliku_do_zaszyfrowania, 'rb')
    klucz = hashlib.sha256(klucz).digest()[:32]
    file_out = open('tmp.txt', 'wb+')
    mode = pyaes.AESModeOfOperationCTR(klucz)
    pyaes.encrypt_stream(mode, file_in, file_out)
    file_out.close()
    file_in.close()
    path = os.getcwd()
    if os.path.isfile(path + "\\" + nazwa_pliku_do_zaszyfrowania):
        os.remove(path + "\\" + nazwa_pliku_do_zaszyfrowania)
        os.rename(path + "\\tmp.txt", path + "\\" + nazwa_pliku_do_zaszyfrowania)


def deszyfruj(nazwa_pliku_do_deszyfracji, klucz):
    file_in = open(nazwa_pliku_do_deszyfracji, "rb")
    file_out = open('tmp.txt', 'wb+')
    klucz = hashlib.sha256(klucz).digest()[:32]
    mode = pyaes.AESModeOfOperationCTR(klucz)
    pyaes.decrypt_stream(mode, file_in, file_out)
    file_out.close()
    file_in.close()
    path = os.getcwd()
    if os.path.isfile(path + "\\" + nazwa_pliku_do_deszyfracji):
        os.remove(path + "\\" + nazwa_pliku_do_deszyfracji)
        os.rename(path + "\\tmp.txt", path + "\\" + nazwa_pliku_do_deszyfracji)

#
# key = b"my_very_long_and_difficult_password"
# szyfruj("dane.txt", key)
# input()
# deszyfruj("dane.txt", key)
