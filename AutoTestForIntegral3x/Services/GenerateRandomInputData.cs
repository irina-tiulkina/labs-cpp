using System;
using System.Globalization;
using System.Text;
using AutoTestForIntegral3x.Models;
using AutoTestForIntegral3x.Services.Interfaces;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;

namespace AutoTestForIntegral3x.Interfaces
{
    internal class GenerateRandomInputData : IGenerateRandomInputData
    {
        private readonly Random _rand;

        public GenerateRandomInputData()
        {
            _rand = new Random();
        }

        public string[] GetPositiveBoundaryValue(double max, double min)
        {
            double leftBoudary = _rand.NextDouble() * min * 1000 * (max - min) + min;
            //leftBoudary = Math.Round(leftBoudary, 3);
            double rightBoudary = _rand.NextDouble() * min * 1000 * (max - leftBoudary) + leftBoudary;
            //rightBoudary = Math.Round(rightBoudary, 3);
            string[] strs = new string[2] {leftBoudary.ToString(CultureInfo.InvariantCulture), rightBoudary.ToString(CultureInfo.InvariantCulture)};
            return strs;
        }

        public Method GetPositiveMethod(int[] methods)
        {
            int m = _rand.Next(0, methods.Length);
            Method strs = new Method(){Name = "", Value = methods[m].ToString(CultureInfo.InvariantCulture) };
            return strs;
        }

        public string GetPositivePolinome(double max, double min, int maxLenght)
        {
            int count = _rand.Next(1, maxLenght);
            var pol = new StringBuilder(count);
            for (int i=0; i < count; i++)
            {
                //long x = unchecked((long)(_rand.NextDouble() * ulong.MaxValue));
                //Int64 maxInt = int.MaxValue;
                double rand = _rand.NextDouble() * min * 1000;
                double coef = rand * (max - min) + min;
                //coef = Math.Round(coef, 3);
                pol.Append(coef.ToString(CultureInfo.InvariantCulture));
                pol.Append(" ");
            }
            //throw new NotImplementedException();
            return pol.ToString();
        }

        public string GetPositiveStep(double max, double min)
        {
            double step = _rand.NextDouble() * (max - min) + min;
            step = Math.Round(step, 6);
            return step.ToString(CultureInfo.InvariantCulture);
            //throw new NotImplementedException();
        }

        public string[] GetNegativeBoundaryValue()
        {
            throw new NotImplementedException();
        }

        public Method GetNegativeMethod()
        {
            throw new NotImplementedException();
        }

        public string GetNegativePolinome()
        {
            throw new NotImplementedException();
        }

        public string GetNegativeStep()
        {
            throw new NotImplementedException();
        }
    }
}