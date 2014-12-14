import std.stdio;
import std.array;
import std.conv;
import std.algorithm;

void main()
{
    int sizeA;
    int sizeB;

    readf(" %d ", &sizeA);
    writeln("sizeA=", sizeA);
    string[] vals = split(stdin.readln());
    // The wrapping in an array is due to map's lazy eval
    int[] A = array(vals.map!(to!int));
    
    readf(" %d ", &sizeB);
    writeln("sizeB=", sizeB);
    vals = split(stdin.readln());
    int[] B = array(vals.map!(to!int));


}
