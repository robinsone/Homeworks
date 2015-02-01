/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment_2;

import java.io.*;

/**
 *
 * @author Eric Robinson
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {


        int[] ruler, ruler2;
        int start = 0;
        int length = 0;
        double height = 0;

        do {
            BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter the length: ");
            String i = "";
            try {
                i = dataIn.readLine();
            } catch (IOException e) {
                System.out.println("Error!");
            }

            length = Integer.parseInt(i);
            height = Math.log(length) / Math.log(2);

        } while (length < 2 || height != Math.round(height));


        System.out.println("");

        ruler = new int[length + 1];

        System.out.println("Recursive");

        Recursive(start, length, ruler);

        for (int x = 0; x <= ruler.length - 1; x++) {
            System.out.print(ruler[x]);
        }

        System.out.println("");

        int w = 0;
        
        for (int z = 0; z <= ruler.length - 1; z++) {
            if (w == 10) {
                w = 0;
            }
            System.out.print(w);
            w++;
        }

        System.out.println("");
        System.out.println("");
        System.out.println("Iterative");

        ruler2 = new int[length + 1];
        iterative(ruler2, start, length, (int) height);

        for (int x = 0; x <= ruler.length - 1; x++) {
            System.out.print(ruler[x]);
        }


        System.out.println("");

        int o = 0;
        
        for (int z = 0; z <= ruler.length - 1; z++) {
            if (o == 10) {
                o = 0;
            }
            System.out.print(o);
            o++;
        }

        System.out.println("");
    }

    public static void Recursive(int start, int end, int[] ruler) {
        int length = end - start;
        int mid = (start + end) / 2;

        if (length <= 2) {
            ruler[mid] = 1;
        } else {
            ruler[mid] = (int) (Math.log(end - start) / Math.log(2));
            Recursive(start, mid, ruler);
            Recursive(mid, end, ruler);
        }

    }

    public static void iterative(int[] ruler2, int l, int r, int h) {
        for (int t = 1, j = 1; t <= h; j += j, t++) {
            for (int i = 0; l + j + i <= r; i += j + j) {
                ruler2[t] = (l + j + i);
            }
        }


    }
}
