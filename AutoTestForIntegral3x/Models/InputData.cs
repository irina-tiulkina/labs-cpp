using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x.Models
{
    public class InputData : ViewModelBase
    {
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

        public string GetInputDataStr()
        {
            var strBuilder = new StringBuilder();
            strBuilder.Append(LeftBoundary);
            strBuilder.Append(" ");
            strBuilder.Append(RightBoundary);
            strBuilder.Append(" ");
            strBuilder.Append(Step);
            strBuilder.Append(" ");
            strBuilder.Append(Method);
            strBuilder.Append(" ");
            strBuilder.Append(Polynome);
            return strBuilder.ToString();
        }
    }
}
