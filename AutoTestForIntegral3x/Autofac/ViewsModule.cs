using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Autofac;
using AutoTestForIntegral3x.view;
using AutoTestForIntegral3x.vm;

namespace AutoTestForIntegral3x.Autofac
{
    internal class ViewsModule : Module
    {
        protected override void Load(ContainerBuilder builder)
        {
            builder.Register(c => new MainViewModel()).AsSelf();
            builder.Register(c => new MainWindow() { DataContext = c.Resolve<MainViewModel>()}).AsSelf();
        }
    }

}
