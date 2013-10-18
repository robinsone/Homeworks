/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Vector;

/**
 *
 * @author ericrobinson
 */
public class main {

    /**
     * @param args the command line arguments
     */
    public static Vector<Integer> picture = new Vector<Integer>();
    public static String freq = "";
    public static Vector<Character> OneFreq = new Vector<Character>();
    public static UnionFind uf;
    public static int maxCols = 0;

    public static void main(String[] args) {
        String file = null;
        if (args.length > 0) {
            file = args[0];

        } else {
            System.out.println("There was no img file in the argument");
            return;
        }

        /*
         * Insert girl.txt into a ArrayList of Pixel
         */


        try {
            BufferedReader reader = new BufferedReader(new FileReader(file));

            String line;// = reader.readLine();


            //image.add(new Pixel(0,0, ' '));
            int xcounter = 0;
            while ((line = reader.readLine()) != null) {
                //System.out.println(line);
                char[] charinline = line.toCharArray();
                for (char c : charinline) {
                    if (c == '+') {
                        picture.add(1);
                    }
                    if (c == ' ') {
                        picture.add(0);
                    }

                    xcounter++;
                }

                maxCols = xcounter;
                xcounter = 0;
                //line = reader.readLine();
            }
        } catch (FileNotFoundException fnf) {
            System.out.println("File not found");
        } catch (IOException ioe) {
            System.out.println("Read/Write Error");
        }

        printPicture();

        uf = new UnionFind(picture.size());

        if (picture.get(0) == 0) {
            uf.union(0, 0);
        }

        for (int i = 1; i < maxCols; i++) {

            if (picture.get(i) == 1) {
                if (picture.get(i) == picture.get(i - 1)) {
                    uf.union(i - 1, i);
                }
            } else {
                uf.union(0, i);
            }


        }

        for (int i = maxCols; i < picture.size(); i++) {
            if (picture.get(i) == 1) {
                if (i % maxCols != 0) {

                    if (picture.get(i - maxCols) == picture.get(i) && picture.get(i - 1) == picture.get(i)) {
                        uf.union(i - 1, i);
                        uf.union(i - maxCols, i);

                    } else if (picture.get(i) == picture.get(i - 1)) {
                        uf.union(i - 1, i);
                    } else if (picture.get(i - maxCols) == picture.get(i)) {
                        uf.union(i - maxCols, i);
                    }
                } else {
                    if (picture.get(i - maxCols) == 1) {
                        if (picture.get(i - maxCols) == picture.get(i)) {
                            uf.union(i - maxCols, i);
                        }
                    }
                }

            } else {
                uf.union(0, i);
            }
        }
        
        System.out.println("\n\n");
        printPictureSet();


        
        //System.out.println(uf.find(2));

    }

    public static void printPictureSet() {
        int xcounter = 0;
        int ycounter = 0;
        
        Vector<Integer> norm = new Vector<Integer>();
        String output = "";
        for (int i = 0; i < picture.size(); i++) {
            if (!norm.contains(uf.find(i))) {
                norm.add(uf.find(i));
            }

            if (xcounter == maxCols) {
                output += '\n';
                xcounter = 0;
            }

            
            char digit = (char) ((char) 64 + norm.indexOf(uf.find(i)));
           
            if (digit == '@') {
                digit = ' ';
            }
            output += digit;
            xcounter++;


        }
        
        
        freq = output;
        
        System.out.println(output);
        System.out.println("\n\n");
        frequency(true);
        System.out.println("\n\n");
        output = "";
        
        for (int i = 0; i < picture.size(); i++) {
            if (!norm.contains(uf.find(i))) {
                norm.add(uf.find(i));
            }

            if (xcounter == maxCols) {
                output += '\n';
                xcounter = 0;
            }

            
            char digit = (char) ((char) 64 + norm.indexOf(uf.find(i)));
            if(OneFreq.contains(digit)){
                digit = ' ';
            }
            if (digit == '@') {
                digit = ' ';
            }
            output += digit;
            xcounter++;


        }
        
        System.out.println(output);
              
    }
    
   
    public static void printPicture() {
        int xcounter = 0;
        int ycounter = 0;

        String output = "";
        for (int i = 0; i < picture.size(); i++) {
            if (xcounter == maxCols) {
                output += '\n';
                xcounter = 0;
            }
            
            
            if(picture.get(i) == 0){
                output += ' ';
            }else{
                output += '+';
            }

            //output += picture.get(i);
            xcounter++;


        }
        System.out.println(output);
    }

    public static void frequency(boolean print) {
        // read in and sort the input strings
        char[] a = freq.toCharArray();
        int N = a.length;
        Arrays.sort(a);

        // create an array of distinct strings and their frequencies
        Record[] records = new Record[N];
        char word = a[0];
        int freqnum = 1;
        int M = 0;
        for (int i = 1; i < N; i++) {
            if (!(a[i] == word)) {
                records[M++] = new Record(word, freqnum);
                word = a[i];
                freqnum = 0;
            }
            freqnum++;
        }
        records[M++] = new Record(word, freqnum);

        //System.out.println(records.length);

        // sort by frequency and print results
        
        Arrays.sort(records, 1, M);
        
            for (int i = 2; i < M; i++) {
                if(records[i].getFreq() == 1){
                    OneFreq.add(records[i].getWord());
                }
                if (print) {
                    System.out.println(records[i].getWord() + ": " + records[i].getFreq());
                }
            }
        

    }
}
