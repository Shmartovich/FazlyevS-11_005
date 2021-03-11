package week3;

import java.util.Scanner;
import java.util.Stack;

public class parentheses {
    public static void main(String[] args) {
        Stack<String> stack = new Stack<>();
        Scanner scanner = new Scanner(System.in);
        String string = scanner.next();


        String[] parenthesesOpen = {"{", "[", "("};
        String[] parenthesesClose = {"}", "]", ")"};


        char[] chars = string.toCharArray();

        String [] charsThatAreStrings = new String[chars.length];

        for(int i =0; i< chars.length;i++){
            charsThatAreStrings[i] = String.valueOf(chars[i]);
        }


        boolean flag = true;
        for (int i = 0; i < chars.length && flag; i++) {
            for (int j = 0; j < parenthesesOpen.length; j++) {
                if (charsThatAreStrings[i].equals(parenthesesOpen[j])) {
                    stack.push(charsThatAreStrings[i]);
                    break;
                }
            }
            for (int j = 0; j < parenthesesClose.length; j++) {
                if (charsThatAreStrings[i].equals(parenthesesClose[j])) {
                    switch(stack.peek()){
                        case("["):
                            if(charsThatAreStrings[i].equals("]")){
                                stack.pop();
                            }
                            else{
                                System.out.println("Error");
                                flag=false;
                            }
                            break;
                        case("{"):
                            if(charsThatAreStrings[i].equals("}")){
                                stack.pop();
                            }
                            else{
                                System.out.println("Error");
                                flag=false;
                            }
                            break;

                        case("("):
                            if(charsThatAreStrings[i].equals(")")){
                                stack.pop();
                            }
                            else{
                                System.out.println("Error");
                                flag=false;
                            }
                            break;

                    }
                    break;

                }
            }
        }
        if (flag && !stack.isEmpty()){
            System.out.println("Не хватает пары");
        }
        else if (flag){
            System.out.println("Все правильно");

        }
    }
}