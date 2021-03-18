package map1;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class main {
    String string;
    main(String string){
        this.string = string;
    }
    Map<String, Integer> numbers = new HashMap<>();




    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();


        main map = new main(string);


        String [] splitString = string.split(" ");


        int i =1 ;
        for(String word:splitString){
            if (map.numbers.containsKey(word)){
                i = map.numbers.get(word);
                i++;
                map.numbers.put(word,i+1);
            }

            map.numbers.put(word,i);
        }

        System.out.println(map.numbers.keySet());
        System.out.println(map.numbers.values());
    }
}

