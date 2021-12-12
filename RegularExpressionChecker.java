/*
3
[a-c]{3}cab+(da)*f
db*a[^def]{2}gh
def[k-p]*p+
5
defkmnpmpp
acbcabbf
pqrstdd
dbaabggh
dbbbbamkgh

*/


//Author: Shaily Roy

import java.util.*;
import java.io.*;


public class Main {
 boolean not = false, yes=true, bb=false, b=false , wrong = false, match = false;
    String fileName,mmm = "",alpha = "abcdefghijklmnopqrstuvwxyz",substr = "", pattern;;
    Stack<String> rstck, strst;
    String[] regArr,str;

 
    public void makeRegexStack(String regArr) {
        rstck = new Stack();
        for (int i = 0; i < regArr.length(); i++) {
            rstck.push("" + regArr.charAt(i));
        }
    }
 
   public boolean matchp() {
        if (this.pattern.contains(strst.peek())) {
            strst.pop();
            return true;
        }
        return false;
    }


    public void makestrstck(String str) {
        strst = new Stack();
        for (int i = 0; i < str.length(); i++) {
            strst.push("" + str.charAt(i));
        }
    }

   

    public boolean match1(String check) {
        if (matcho(check)) {
            while (matcho(check));
            return true;
        }

  else {
            return false;
        }
    }

    public void matchmatch(String check) {
        while (matcho(check));
    }

    public boolean matcho(String check) {
        String temp = "";
        for (int i = 1; i <= check.length(); i++) {
            if (strst.size() - i >= 0) {
                temp = strst.get(strst.size() - i) + temp;
              
            }
        }
        if (check.equals(temp)) {
            
            for (int i = 0; i < check.length(); i++) {
                strst.pop();
            }
            return true;
        }
        return false;
    }

 
    public boolean matchChar(String check) {
        if (strst.empty()) {
            return true;
        }
        if (check.equals(strst.peek())) {
            strst.pop();
            return false;
        } 
  
  else {
            return true;
        }
    }

 
    public void pattern() {
        this.not = false;
        String temp = "";
        String temp2 = "";
        while (!rstck.empty()) {
            if (rstck.peek().equals("[")) {
                rstck.pop();
                break;
            } 
   
   else if (rstck.peek().equals("^")) {
                rstck.pop();
                this.not = true;
            } 
   
   else {
                temp += rstck.pop();
            }
        }
        this.pattern = temp;

        if (temp.contains("-")) {
            for (int i = temp.charAt(2); i <= temp.charAt(0); i++) {
                temp2 += (char) i;
            }
            this.pattern = temp2;
        }

        if (this.not) {
            this.pattern = this.alpha.replace(this.pattern, "");
        }
    }

 

    public void matchFxL() {
        String temp = "";
        while (!rstck.empty()) {
            if (rstck.peek().equals("{")) {
                rstck.pop();
                rstck.pop();
                break;
            } 
   
   else {
                temp = rstck.pop() + temp;
            }
        }
        int count = Integer.parseInt(temp);
        pattern();
        for (int i = 0; i < count; i++) {
            if (strst.empty()) {
                this.wrong = true;
                return;
            }
            boolean matched = matchp();
            if (!matched) {
                this.wrong = true;
                return;
            }
        }
    }

     public void evaluate() {

        
  for(int i = 0; i < str.length; i++) {
            evExpr(str[i]);
            if (this.match) {
                System.out.println("YES, " + mmm);
            } else {
                System.out.println("NO, 0");
            }
            this.match = false;
            this.mmm = "";
        }
    }
 
  public void evExpr(String str) {

 for (int i = 0; i < regArr.length; i++) {
            makeRegexStack(regArr[i]);
            makestrstck(str);
           
     while (!rstck.empty()) {
                //checking stack empty or not
                if (rstck.peek().equals("}")) {
                    rstck.pop();
                    matchFxL();
                } 
    
    else if (rstck.peek().equals("]")) {
                    rstck.pop();
                    pattern();
                    wrong = !matchp();
                  
                    if (wrong) {
                        break;
                    }
                } 
    
    else if (this.alpha.contains(rstck.peek())) {
                    wrong = matchChar(rstck.pop());
                    if (wrong) {
                        wrong = false;
                        break;
                    }
                } 
    
    else if (rstck.peek().equals("?")) {
                    rstck.pop();
                    if (rstck.peek().equals(")")) {
                        rstck.pop();
                        while (!rstck.peek().equals("(")) {
                            substr = rstck.pop() + substr;
                        }
                        rstck.pop();
                        matcho(substr);
                    } else {
                        matcho(rstck.pop());
                    }
                }

    else if (rstck.peek().equals("*")) {
                    rstck.pop();
                    if (rstck.peek().equals(")")) {
                        rstck.pop();
                        while (!rstck.peek().equals("(")) {
                            substr = rstck.pop() + substr;
                        }
                        rstck.pop();
                        matchmatch(substr);
                    } 
     
     else if (rstck.peek().equals("]")) {
                        rstck.pop();
                        pattern();
                        while (matchp()) {
                            if (strst.empty()) {
                                break;
                            }
                        }
                  
                    } 
     
     
     else {
                        matchmatch(rstck.pop());
                    }
     
     
                } 
    
    else if (rstck.peek().equals("+")) {
                    rstck.pop();
                    if (rstck.peek().equals(")")) {
                        rstck.pop();
                        while (!rstck.peek().equals("(")) {
                            substr = rstck.pop() + substr;
                        }
                        rstck.pop();
                        wrong = match1(substr);
                    } 
     
     else {
                        wrong = !match1(rstck.pop());
                        if (wrong) {
                            wrong = false;
                            break;
                        }
                    }
                }
            }
           
     
            if (rstck.empty() && strst.empty() && !wrong) {
                mmm += (i + 1) + " ";
                this.match = true;
            }
            wrong = false;
            substr = "";
        }
    }
  

  
  public static void main(String[] args) {
    
        try{
            Scanner sc = new Scanner(new File("input.txt"));
                   Main re=new Main();

            int rCnt = Integer.parseInt(sc.nextLine());
            re.regArr = new String[rCnt];
            
            for(int i = 0; i < re.regArr.length; i++) {
                re.regArr[i] = sc.nextLine();
            }
            int strCount = Integer.parseInt(sc.nextLine());
            re.str = new String[strCount];
            
   
            for(int i = 0; i < re.str.length; i++) {
                re.str[i] = sc.nextLine();
            }
     
            re.evaluate();
        }
  catch (Exception e) {

        }
    }}
