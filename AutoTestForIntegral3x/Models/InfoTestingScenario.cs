using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AutoTestForIntegral3x.Interfaces;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x.Models
{
    public class InfoTestingScenario 
    {
        public string Name { get;  set; }
        public bool IsInputBorder { get; set; }
        public bool IsInputStep { get; set; }
        public bool IsInputMethod { get; set; }
        public bool IsInputPolinome { get; set; }
    }
}
