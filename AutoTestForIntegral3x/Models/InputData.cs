using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x.Models
{
    public class InputData : ViewModelBase
    {
        public const double MinBoundary = 1.7E-308;
        public const double MaxBoundary = 1.7E+308;
        public const double MinStep = 0.000001;
        public const double MaxStep = 0.5;
        public static readonly int[] ValidMethods = new[] {1, 2, 3};
        public const double MaxCoeff  = 1.7E+308;
        public const double MinCoeff  = 1.7E-308;
        public const int MaxLenghtPolynome  = 16;

        private string _leftBoundary;
        private string _rightBoundary;
        private string _step;
        private string _polynome;
        private Method _method;

        public string LeftBoundary
        {
            get => _leftBoundary;
            set
            {
                _leftBoundary = value;
                OnPropertyChanged();
            }
        }

        public string RightBoundary
        {
            get => _rightBoundary;
            set
            {
                _rightBoundary = value; 
                OnPropertyChanged();
            }
        }

        public string Step
        {
            get => _step;
            set
            {
                _step = value; 
                OnPropertyChanged();
            }
        }

        public string Polynome
        {
            get => _polynome;
            set
            {
                _polynome = value;
                OnPropertyChanged();
            }
        }

        public Method Method
        {
            get => _method;
            set
            {
                _method = value;
                OnPropertyChanged();
            }
        }

        public override string ToString()
        {
            var strBuilder = new StringBuilder();
            strBuilder.Append(LeftBoundary);
            strBuilder.Append(" ");
            strBuilder.Append(RightBoundary);
            strBuilder.Append(" ");
            strBuilder.Append(Step);
            strBuilder.Append(" ");
            strBuilder.Append(Method.Value);
            strBuilder.Append(" ");
            strBuilder.Append(Polynome);
            return strBuilder.ToString();
        }

        public bool IsValidBoundary()
        {
            return double.TryParse(LeftBoundary, out double l)
                && double.TryParse(RightBoundary, out double r)
                && l < r
                && l > MinBoundary && l < MaxBoundary
                && r > MaxBoundary && r < MaxBoundary;
        }

        public bool IsValidStep => double.TryParse(Step, out double step)
                                   && step > MinStep && step < MaxStep;

        public bool IsValidMethod => int.TryParse(Method.Value, out int method) 
                                     && ValidMethods.Contains(method);
        public bool IsValidPolynome()
        {
            var ps = Polynome.Split(' ');
            if (ps.Length > MaxLenghtPolynome || ps.Length == 0)
                return false;
            foreach (var p in ps)
            {
                if (!double.TryParse(p, out double dp) || dp < MinCoeff || dp > MaxCoeff)
                    return false;
            }
            return true;
        }

    }
}
