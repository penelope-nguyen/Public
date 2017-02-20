import java.util.*;

public class HW2_1 {

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
    
    public static boolean markerisPossible(HashMap marker_bases, HashMap DNA_bases) { 
    	for (Object key: marker_bases.keySet()) { 
            // System.out.print(key +  " " );
            int DNA_count = (int)DNA_bases.get(key);
            int marker_count = (int)marker_bases.get(key);
            // System.out.println(DNA_count + " | " + marker_count);
           
            if (DNA_count < marker_count) { 
                return false; 
            }
        }
    	return true; 
    }
    public static void main(String[] args) {
        String DNA = "ATGGAT";
        String marker = "AGGT";
        int m_length = marker.length();
        int dna_length = DNA.length(); 
        int diff = dna_length - m_length;
        char [] bases = {'A', 'C', 'G', 'T'};
        int expression_count = 0;
        HashMap DNA_bases = new HashMap();
        HashMap marker_bases = new HashMap();
        HashSet mutations = new HashSet();
        mutations.add(marker);
        HashMap DNA_subs = new HashMap();
        
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
        
        for (int start = 0; start < m_length; start++) { 
        	for (int end = m_length; end > start + 1; end --) {
        		String mutation = marker.substring(start, end);
        		String rev = new StringBuilder(mutation).reverse().toString();
        		String stuff = marker.substring(0, start) + rev + marker.substring(end, m_length);
        		mutations.add(stuff);
        	}
        }
		
        for (int start = 0; start <= diff; start++) { 
        	for (int end = dna_length; end >start + 1; end--) { 
        		String DNA_sub = DNA.substring(start, end);
        		if (DNA_sub.length() < m_length)
        			continue; 
        		System.out.println(DNA_sub);
        		
        		if (DNA_subs.containsKey(DNA_sub)) {
        			int DNA_count = (int)(DNA_subs.get(DNA_sub));
        			DNA_subs.put(DNA_sub, DNA_count + 1);
        		}        		
        		else 
        			DNA_subs.put(DNA_sub, 1);
        	}
        	
        }
        
        for (Object mutation: mutations) { 
        	if (DNA_subs.containsKey(mutation))
        		expression_count += (int)(DNA_subs.get(mutation));
        }

   }
    
}
