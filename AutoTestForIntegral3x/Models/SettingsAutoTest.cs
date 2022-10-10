using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x.Models
{
    public class SettingsAutoTest : ViewModelBase
    {
        public SettingsAutoTest(ObservableCollection<Method> methods, ObservableCollection<InfoTestingScenario> testingScenarios)
        {
            Methods = methods;
            TestingScenarios = testingScenarios;
        }

        private InputData _input;
        private int _countTests;
        private bool _isPositiveTests;
        private double _accuracy;
        private InfoTestingScenario _scenario;

        public ObservableCollection<Method> Methods { get; }
        public ObservableCollection<InfoTestingScenario> TestingScenarios { get; }

        public InfoTestingScenario Scenario
        {
            get => _scenario;
            set
            {
                _scenario = value; 
                OnPropertyChanged();
                if (!_scenario.IsInputBorder)
                {
                    Input.LeftBoundary = null;
                    Input.RightBoundary = null;
                }

                if (!_scenario.IsInputMethod)
                {
                    Input.Method = null;
                }

                if (!_scenario.IsInputPolinome)
                {
                    Input.Polynome = null;
                }

                if (!_scenario.IsInputStep)
                {
                    Input.Step = null;
                }
            }
        }

        public InputData Input
        {
            get => _input;
            set
            {
                _input = value;
                OnPropertyChanged(nameof(Input));
                //this.RaiseAndSetIfChanged(ref input, value);
            }
        }

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
            }
        }

        public bool IsNegativeTests => !IsPositiveTests;

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
