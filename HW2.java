/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw2;
import java.util.*;
/**
 *
 * @author zvy989
 */
public class HW2 {

    /**
     * @param args the command line arguments
     */
    
    public static void countBases(String sequence, HashMap map) { 
        for (char base: sequence.toCharArray()) { 
            int char_count = (int)(map.get(base)) + 1;
            map.put(base, char_count);
        }
    }
    public static void printMap(HashMap map) { 
        
        System.out.println("Printing hashmap...");
        for (Object key: map.keySet())
        {
            Object value = map.get(key);
            System.out.println(key + ": " + value);
        }
    }
    public static void main(String[] args) {
        String DNA = "ATGGAT";
        String marker = "ACGT";
        char [] bases = {'A', 'C', 'G', 'T'};
        HashMap DNA_bases = new HashMap();
        HashMap marker_bases = new HashMap();
        
        // Put all bases into each hashmap 
        for (int i = 0; i < bases.length; i++) {
            DNA_bases.put(bases[i], 0);
            marker_bases.put(bases[i], 0);
        }
        
        // Count how many times each base shows up in DNA sequence 
        System.out.println(DNA);
        countBases(DNA, DNA_bases);
        printMap(DNA_bases);
        
        System.out.println("Map for: " + marker);
        countBases(marker, marker_bases);
        printMap(marker_bases);
        
        for (Object key: marker_bases.keySet()) { 
            System.out.print(key +  " " );
            int DNA_count = (int)DNA_bases.get(key);
            int marker_count = (int)marker_bases.get(key);
            System.out.println(DNA_count + " | " + marker_count);
            if (DNA_count < marker_count) { 
                System.out.println("not possible");
            }
            else                 
                System.out.println("possible!");
        }
       
       
   }
    
}
