using System;

namespace blackbox_net.test
{
    static class Program
    {
        static void Main(string[] args)
        {
            var bb = new BlackBox("this is a config string");
            Console.Out.Write(bb.call(1, 2, 3));
        }
    }
}
