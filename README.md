# AxControl
Repository to control an axis

Zum Kompilieren des Hauptprogramms
    g++ -g testInterpolator.cpp -o testInterpolator
eingeben.


---------- Code Snippets ----------

Strings einlesen und ausgeben
    std::string command = "";
    std::cout<<"Hello World" << std::endl;
    std::cin >> command;
    std::cout << command << std::endl;

    
ReadWrite
/*
class Program
    {
        static void Main(string[] args)
        {
            // Get the directories currently on the C drive.
            DirectoryInfo[] cDirs = new DirectoryInfo(@"c:\").GetDirectories();

            // Write each directory name to a file.
            using (StreamWriter sw = new StreamWriter("CDriveDirs.txt"))
            {
                foreach (DirectoryInfo dir in cDirs)
                {
                    sw.WriteLine(dir.Name);
                }
            }

            // Read and show each line from the file.
            string line = "";
            using (StreamReader sr = new StreamReader("CDriveDirs.txt"))
            {
                while ((line = sr.ReadLine()) != null)
                {
                    Console.WriteLine(line);
                }
            }
        }
    }
*/