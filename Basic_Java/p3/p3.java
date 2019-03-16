import java.util.*;

class Stack{
    public String stack;
    public int sp;

    Stack(String s){
        stack=s;
        sp=s.length()-1;
    };

    Stack(){
        stack="";
        sp=0;
    }

    public void push(String s){
        stack=stack+s;
        sp++;
    };

    public String pop(){
        String str=stack.substring(sp-1,sp);
        stack=stack.substring(0,sp-1);
        sp--;
        return str;
    }
};

class Checker{
    public static boolean parenthesisChecker(String exp){
        int index=0;
        Stack stack=new Stack();
        String popped;
        System.out.println("Token\tStack");
        while(index<exp.length()){
            char chr=exp.charAt(index);
            System.out.println(chr+"\t"+stack.stack);
            if(chr=='(' || chr=='{' || chr=='['){
                stack.push(Character.toString(chr));
            }
            else if(chr==')'){
                popped=stack.pop();
                if(!popped.equals("("))return false;
            }
            else if(chr=='}'){
                popped=stack.pop();
                if(!popped.equals("{"))return false;
            }
            else if(chr==']'){
                popped=stack.pop();
                if(!popped.equals("["))return false;
            }
            index++;
        };
        if (stack.sp!=0)return false;
        return true;
    };
};
public class p3{
    public static void main(String[] args){
        String exp;
        System.out.print("Enter expression :");
        Scanner s=new Scanner(System.in);
        exp=s.nextLine();
        System.out.println("------------------------------");
        System.out.println("\nParenthesis Matching :"+Checker.parenthesisChecker(exp));
        System.out.println("------------------------------");
    };
}