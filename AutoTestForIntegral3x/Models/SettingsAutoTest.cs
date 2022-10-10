using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x.Models
{
    public class SettingsAutoTest : ViewModelBase
    {
        private int _countTests;
        private bool _isPositiveTests;
        private bool _isFixStep;
        private double _accuracy;
        private bool _isUnvalidMethod;


        public bool IsUnvalidMethod
        {
            get => _isUnvalidMethod;
            set
            {
                _isUnvalidMethod = value; 
                OnPropertyChanged();
                OnPropertyChanged(nameof(IsValidMethod));
            }
        }

        public bool IsValidMethod => !IsUnvalidMethod;
        public int CountTests
        {
            get => _countTests;
            set
            {
                _countTests = value;
                OnPropertyChanged();
            }
        }

        public bool IsPositiveTests
        {
            get => _isPositiveTests;
            set
            {
                _isPositiveTests = value;
                OnPropertyChanged();
                OnPropertyChanged(nameof(IsNegativeTests));
                if (_isPositiveTests)
                {
                    IsFixStep = false;
                    IsUnvalidMethod = false;
                }
            }
        }

        public bool IsNegativeTests => !IsPositiveTests;

        public bool IsFixStep
        {
            get => _isFixStep;
            set
            {
                _isFixStep = value; 
                OnPropertyChanged();
            }
        }

        public double Accuracy
        {
            get => _accuracy;
            set
            {
                _accuracy = value;
                OnPropertyChanged();
            }
        }
    }
}
