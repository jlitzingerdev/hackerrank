import std.stdio;
import std.array;
import std.conv;
import std.algorithm;

int[] missingNumbers(int[] A, int[] B)
{
    if (A.length == B.length) {
        return [];
    }

    int min = 99999;
    int max = 0;

    foreach (int i; B) {
        if (i > max) {
            max = i;
        }
        if (i < min) {
            min = i;
        }
    }

    int[] t = new int[(max - min) + 1];
    
    foreach(int i; B) {
        t[i % min]++;
    }

    foreach(int i; A) {
        t[i % min]--;
    }

    int[] res;
    foreach(int i,v ; t) {
        if (v > 0) {
            res ~= i + min;
        }
    }
    
    return res;
}


void main()
{
    int sizeA;
    int sizeB;

    readf(" %d ", &sizeA);
    string[] vals = split(stdin.readln());
    // The cast to an array is due to map's lazy eval
    int[] A = array(vals.map!(to!int));
    
    readf(" %d ", &sizeB);
    vals = split(stdin.readln());
    int[] B = array(vals.map!(to!int));

    int[] res = missingNumbers(A,B);
    foreach (int i; res) {
        writef("%d ", i);
    }
    write("\n");
}
