# -*- coding: utf-8 -*-
# Generated by Django 1.11.7 on 2017-11-06 21:35
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('miotask', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='extenduser',
            name='random_number',
            field=models.PositiveSmallIntegerField(default=0),
        ),
    ]
