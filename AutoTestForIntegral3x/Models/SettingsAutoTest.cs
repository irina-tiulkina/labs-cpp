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
        public SettingsAutoTest()
        {
            Methods = new ObservableCollection<Method>()
            {
                new Method() { Name = "Метод парабол", Value = "1" },
                new Method() { Name = "Метод трапеций", Value = "2" },
                new Method() { Name = "Метод Монте-Карло", Value = "3" }
            };
            Scenario = new InfoTestingScenario();
            Input = new InputData();
        }

        private InputData _input;
        private int _countTests;
        private double _accuracy;
        private InfoTestingScenario _scenario;

        public ObservableCollection<Method> Methods { get; }
        public InfoTestingScenario Scenario
        {
            get => _scenario;
            set
            {
                _scenario = value; 
                OnPropertyChanged();
                //if (!_scenario.IsInputBorder)
                //{
                //    Input.LeftBoundary = null;
                //    Input.RightBoundary = null;
                //}

                //if (!_scenario.IsInputMethod)
                //{
                //    Input.Method = null;
                //}

                //if (!_scenario.IsInputPolinome)
                //{
                //    Input.Polynome = null;
                //}

                //if (!_scenario.IsInputStep)
                //{
                //    Input.Step = null;
                //}
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

        public double Accuracy
        {
            get => _accuracy;
            set
            {
                _accuracy = value;
                OnPropertyChanged();
            }
        }

        public bool IsValidInputData()
        {
            bool setting = CountTests > 0
                && Accuracy > 0.000001
                && Accuracy < 1;
            bool scenario =  
                 (Scenario.IsInputPolinome || Scenario.IsInputStep ||
                    Scenario.IsInputBorder || Scenario.IsInputMethod);
            bool border = Input != null
                            && (!Scenario.IsInputBorder
                                || (!string.IsNullOrEmpty(Input.LeftBoundary)
                                    && !string.IsNullOrEmpty(Input.RightBoundary)
                                    && Input.IsValidBoundary()));
            bool method = Input != null
                            && (!Scenario.IsInputMethod
                                || (!string.IsNullOrEmpty(Input.Method.Value)
                                    && Input.IsValidMethod));
            bool polinome = Input != null
                            && (!Scenario.IsInputPolinome
                                || (!string.IsNullOrEmpty(Input.Polynome)
                                    && Input.IsValidPolynome()));
            bool step = Input != null
                && (!Scenario.IsInputStep
                    || !string.IsNullOrEmpty(Input.Step)
                    && Input.IsValidStep);

            bool n = !(Scenario.IsInputPolinome && Scenario.IsInputBorder && Scenario.IsInputMethod &&
                       Scenario.IsInputStep);

            return setting && scenario && polinome && method && step && n;
        }

    }
}
