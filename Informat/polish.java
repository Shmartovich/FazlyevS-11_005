package week3;

import java.util.Scanner;
import java.util.Stack;

public class polish {

    static boolean tryParseInt(String input) {
        try {
            Integer.parseInt(input);
        }
        catch (Exception e) {
            return false;
        }
        return true;
    }

    public static void main(String[] args){
        Stack<Integer> stack = new Stack<>();
        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();
        String [] split = string.split (" ");


        for(int i =0 ; i< split.length;i++){
            if (tryParseInt(split[i])) {
                int x = Integer.parseInt(split[i]);
                stack.push(x);
            }
            else{
                Integer a =stack.pop();
                Integer b =stack.pop();
                switch(split[i]){
                    case("+"):
                        stack.push(a+b);
                        break;
                    case("-"):
                        stack.push(b-a);
                        break;
                    case("*"):
                        stack.push(a*b);
                        break;
                    case("/"):
                        stack.push(a/b);
                        break;
                }
            }
        }
        Integer probableResult = stack.pop();
        if(stack.isEmpty()){
            System.out.println(probableResult);
        }
        else{
            System.out.println("Не правильная запись выражения");
        }



    }
}

