using Autofac;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;
using AutoTestForIntegral3x.Autofac;
using AutoTestForIntegral3x.view;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x
{
    /// <summary>
    /// Логика взаимодействия для App.xaml
    /// </summary>
    public partial class App : Application
    {
        public App()
        {
            this.DispatcherUnhandledException += App_DispatcherUnhandledException;
        }
        protected override void OnStartup(StartupEventArgs e)
        {
            var builderBase = new ContainerBuilder();

            //builderBase.RegisterModule(new RepositoryModule());
            builderBase.RegisterModule(new ViewsModule());

            var containerBase = builderBase.Build();
            
            //containerBase.Resolve<IUserService>()

            var viewBase = containerBase.Resolve<MainWindow>();

            viewBase.Show();
        }

        void App_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs e)
        {
            MessageBox.Show("Ошибка\n" + e.Exception.StackTrace + " " + "Исключение: "
                            + e.Exception.GetType().ToString() + " " + e.Exception.Message);

            e.Handled = true;
        }
    }
}
