
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutoTestForIntegral3x.Models
{
    public class ResultTest
    {
        public int Num { get; set; }
        public string InputDate { get; set; }
        public string TypeTest { get; set; }
        public string PlanResult { get; set; }
        public string FactResult { get; set; }
        //public string Conculation => FactResult == PlanResult ? "Тест пройден" : "Тест не пройден";
        public string Conculation { get; set; }
    }
}
