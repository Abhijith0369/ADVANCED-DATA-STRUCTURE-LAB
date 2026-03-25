package abhijith;
import java.util.Scanner;

class InvalidUserException extends Exception
{
    InvalidUserException(String message)
    {
        super(message);
    }
}

public class UserAuthentication
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String username, password;

        System.out.print("Enter Username: ");
        username = sc.nextLine();

        System.out.print("Enter password: ");
        password = sc.nextLine();

        try
        {
            if (!username.equals("admin") || !password.equals("1234"))
            {
                throw new InvalidUserException("Invalid Username or Password!");
            }

            System.out.println("Login Successful!");
        }
        catch (InvalidUserException e)
        {
            System.out.println("Exception: " + e.getMessage());
        }

        sc.close();
    }
}