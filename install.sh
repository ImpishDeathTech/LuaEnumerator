# /usr/bin/sh
IN=enum.cxx
OBJ=enum.o
OUT=enum.so
DEST=/usr/lib/lua/5.4/


echo Compiling $IN to $OUT...
c++ $IN -c -llua -fPIC && c++ $OBJ -shared -o $OUT

echo Moving to $DEST
sudo mv $OUT $DEST

echo Cleaning up...
rm $OBJ

