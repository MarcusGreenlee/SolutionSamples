using System;
using System.Xml.Linq;

namespace SimpleBookingSystem
{
    internal class Program
    {
        static private string?[] seatAssignments = new string[15];

        static void Main(string[] args)
        {
            char command = getCommand();
            while (command != 'Q')
            {
                switch (command)
                {
                    case 'B':
                        CustBooking();
                        break;

                    case 'C':
                        CustCancel();
                        break;

                    case 'P':
                        PrintSeat();
                        break;

                    default:
                        Console.WriteLine("Invalid command request");
                        break;
                }

                command = getCommand();
            }
        }

        private static char getCommand()
        {
            Console.Write("Enter a command (‘b’ or ‘B’ for book a seat, ‘c’ or ‘C’ cancel a seat, ‘p’ or ‘P’ for print the seating assignments, and ‘q’ or ‘Q’ for quit) = ");
            string? inputValue = Console.ReadLine();

            // Actions are undefined if the ReadLine() returns a null or any character than B,C,P, or Q.
            char command = 'U';
            if (inputValue != null)
            {
                char[] validCommands = { 'B', 'C', 'P', 'Q'};
                char value = Char.ToUpper(inputValue[0]);

                if (validCommands.Contains(value))
                    command = value;
            }

            return command;
        }

        // Method: FindEmptySeat
        // Purpose: searches for a seat that has not been claimed by a name
        // Parameters
        // returns:
        private static int FindEmptySeat()
        {
            int index = 0;
            foreach (string? name in seatAssignments)
            {
                if (name == null)
                    return index;

                ++index;
            }

            return -1;
        }

        // Method: FindCustomerSeat
        // purpose: Checks what the costumners seat is, if they have one
        // Parameters
        // returns:
        private static int FindCustomerSeat(string customer)
        {
            int index = 0;
            foreach (string? name in seatAssignments)
            {
                if (name == customer)
                    return index;

                ++index;
            }

            return -1;
        }

        private static string? getCustomerName()
        {
            Console.Write("Please enter customer name: ");
            string? name = Console.ReadLine();

            if (name == null)
            {
                Console.WriteLine("Customer name is invalid. Unable to complete the request.");
            }

            return name;
        }

        // Method: CustBooking
        // Parameters
        //      
        // returns:
        private static void CustBooking()
        {
            string? name = getCustomerName();

            if (name != null)
            {
                int seat = FindCustomerSeat(name);

                // If the customer doesn't already have a seat, then find one
                if (seat == -1)
                {
                    seat = FindEmptySeat();

                    // if there is a seat available then assign the customer to it
                    if (seat != -1)
                    {
                        seatAssignments[seat] = name;
                    }
                    else
                    {
                        Console.WriteLine("The flight is completely booked. Unable to assign a seat.");
                    }
                }
                else 
                {
                    Console.WriteLine("Customer {0} is already in seat {1}", name, seat);
                }
            }
        }


        private static void CustCancel()
        {
            string? name = getCustomerName();

            if (name != null)
            {
                int seat = FindCustomerSeat(name);
                if (seat != -1)
                {
                    seatAssignments[seat] = null;
                }
                else
                {
                    Console.WriteLine("This customer does not have an assigned seat. Unable to cancel.");
                }
            }
        }

        //Method: Print
        // Parameters
        //      
        // Returns: 
        private static void PrintSeat()
        {
            string? name = getCustomerName();

            if (name != null)
            {
                int seat = FindCustomerSeat(name);
                if (seat != -1)
                    Console.WriteLine("{0} is in seat {1}.", name, seat);
                else
                    Console.WriteLine("{0} does not have a seat.", name);
            }

            return;
        }
    }
}
