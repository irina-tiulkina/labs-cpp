using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AutoTestForIntegral3x.Interfaces;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x.Models
{
    public enum TypeTest
    {
        PositiveVarStepAndMethod, // 1.1
        NegativeVarStepAndMethod, // 1.2
    }

    public class InfoTestingScenario : ViewModelBase
    {
        private bool _isPositiveTest;
        private bool _isInputBorder;
        private bool _isInputStep;
        private bool _isInputMethod;
        private bool _isInputPolinome;

        //public TypeTest TypeTest { get; set; } = TypeTest.PositiveVarStepAndMethod;
        public bool IsPositiveTest
        {
            get => _isPositiveTest;
            set
            {
                _isPositiveTest = value;
                OnPropertyChanged();
            }
        }

        //public string Name { get;  set; }
        public bool IsInputBorder
        {
            get => _isInputBorder;
            set
            {
                _isInputBorder = value;
                OnPropertyChanged();
            }
        }

        public bool IsInputStep
        {
            get => _isInputStep;
            set
            {
                _isInputStep = value;
                OnPropertyChanged();
            }
        }

        public bool IsInputMethod
        {
            get => _isInputMethod;
            set
            {
                _isInputMethod = value;
                OnPropertyChanged();
            }
        }

        public bool IsInputPolinome
        {
            get => _isInputPolinome;
            set
            {
                _isInputPolinome = value;
                OnPropertyChanged();
            }
        }
    }
}
